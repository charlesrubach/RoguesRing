#include <pebble.h>
#include "text.h"
#include "constants.h"
	
static Window *window, *scroll_window;
static TextLayer *text_layer;
static ScrollLayer *scroll_layer;
static BitmapLayer *image_layer_1, *image_layer_2;
static GBitmap *image_1, *image_2;
static Layer *window_layer;

static PropertyAnimation *property_animation_1 = NULL, *property_animation_2 = NULL;
GRect image_locations[3];

static const int vert_text_layer_padding = 25;
static const int vert_scroll_text_padding = 4;
static int8_t current_image = 0;

//static void load_up_image(GBitmap *image, ResHandle resource, BitmapLayer *image_layer, InverterLayer *inverter_layer, GRect *bounds) {
static void load_up_image(GBitmap **image, uint32_t resource, BitmapLayer **image_layer, GRect bounds) {
	gbitmap_destroy(*image);
	bitmap_layer_destroy(*image_layer);
	
	*image = gbitmap_create_with_resource(resource);
	
	// Use GCompOpClear to display the black portions of the image
	*image_layer = bitmap_layer_create(bounds);
	bitmap_layer_set_bitmap(*image_layer, *image);
	bitmap_layer_set_background_color(*image_layer, GColorBlack);
	layer_add_child(window_layer, bitmap_layer_get_layer(*image_layer));
}

void destroy_property_animation(PropertyAnimation **prop_animation) {
    if (*prop_animation == NULL) {
        return;
    }
    if (animation_is_scheduled((Animation*) *prop_animation)) {
        animation_unschedule((Animation*) *prop_animation);
    }
    property_animation_destroy(*prop_animation);
    *prop_animation = NULL;
}

static void animation_started_image_1(Animation *animation, void *data) {
  // Animation started
	(void)animation;
	(void)data;
}

static void animation_stopped_image_1(Animation *animation, bool finished, void *data) {
  // Animation stopped
	(void)animation;
	(void)data;	
}

static void animation_started_image_2(Animation *animation, void *data) {
  // Animation started
	(void)animation;
	(void)data;
}

static void animation_stopped_image_2(Animation *animation, bool finished, void *data) {
  // Animation stopped
	(void)animation;
	(void)data;	
	
	// Destroy old image
	layer_remove_from_parent(bitmap_layer_get_layer(image_layer_1));
	
	// Load up new image
	GRect bounds = layer_get_frame(window_layer);
	load_up_image(&image_1, (uint32_t)hieroglyph[current_image], &image_layer_1, bounds);	
}

// Move images down
static void up_click_handler(ClickRecognizerRef recognizer, Window *window) {	
	int8_t next_image = (current_image - 1 < 0) ? TOTAL_HIEROGLYPHS : current_image - 1;
	
	// Load image above
	load_up_image(&image_2, (uint32_t)hieroglyph[next_image], &image_layer_2, image_locations[0]);	
	// Move image
	property_animation_destroy(property_animation_1);
	property_animation_destroy(property_animation_2);
	
	property_animation_1 = property_animation_create_layer_frame(bitmap_layer_get_layer(image_layer_1), &image_locations[1], &image_locations[2]);
	property_animation_2 = property_animation_create_layer_frame(bitmap_layer_get_layer(image_layer_2), &image_locations[0], &image_locations[1]);

	animation_set_duration((Animation*)property_animation_1, ANIMATION_DURATION);
	animation_set_duration((Animation*)property_animation_2, ANIMATION_DURATION);

	animation_set_curve((Animation*)property_animation_1, AnimationCurveLinear);
	animation_set_curve((Animation*)property_animation_2, AnimationCurveLinear);
	
	animation_set_handlers((Animation*) property_animation_1, (AnimationHandlers) {
		.started = (AnimationStartedHandler) animation_started_image_1,
		.stopped = (AnimationStoppedHandler) animation_stopped_image_1,
	}, NULL);
	
	animation_set_handlers((Animation*) property_animation_2, (AnimationHandlers) {
		.started = (AnimationStartedHandler) animation_started_image_2,
		.stopped = (AnimationStoppedHandler) animation_stopped_image_2,
	}, NULL );	
	
	animation_schedule((Animation*)property_animation_1);
	animation_schedule((Animation*)property_animation_2);

	current_image--;	
	if(current_image < 0) { current_image = TOTAL_HIEROGLYPHS; }
}

// Rotate Counter-Clockwise
static void down_click_handler(ClickRecognizerRef recognizer, Window *window) {	
	int8_t next_image = (current_image + 1 > TOTAL_HIEROGLYPHS) ? 0 : current_image + 1;
	
	// Load image below
	load_up_image(&image_2, (uint32_t)hieroglyph[next_image], &image_layer_2, image_locations[2]);	
	// Move image
	property_animation_destroy(property_animation_1);
	property_animation_destroy(property_animation_2);
	
	property_animation_1 = property_animation_create_layer_frame(bitmap_layer_get_layer(image_layer_1), &image_locations[1], &image_locations[0]);
	property_animation_2 = property_animation_create_layer_frame(bitmap_layer_get_layer(image_layer_2), &image_locations[2], &image_locations[1]);

	animation_set_duration((Animation*)property_animation_1, ANIMATION_DURATION);
	animation_set_duration((Animation*)property_animation_2, ANIMATION_DURATION);

	animation_set_curve((Animation*)property_animation_1, AnimationCurveLinear);
	animation_set_curve((Animation*)property_animation_2, AnimationCurveLinear);
	
	animation_set_handlers((Animation*) property_animation_1, (AnimationHandlers) {
		.started = (AnimationStartedHandler) animation_started_image_1,
		.stopped = (AnimationStoppedHandler) animation_stopped_image_1,
	}, NULL);
	
	animation_set_handlers((Animation*) property_animation_2, (AnimationHandlers) {
		.started = (AnimationStartedHandler) animation_started_image_2,
		.stopped = (AnimationStoppedHandler) animation_stopped_image_2,
	}, NULL );	
	
	animation_schedule((Animation*)property_animation_1);
	animation_schedule((Animation*)property_animation_2);	
	
	current_image++;	
	if(current_image > TOTAL_HIEROGLYPHS) { current_image = 0; }
}

static void scroll_window_load(Window *window){
	Layer *window_layer = window_get_root_layer(window);
	GRect bounds = layer_get_frame(window_layer);
	GRect max_text_bounds = GRect(0, 0, bounds.size.w, 2000);
	
	// Initialize the scroll layer
	scroll_layer = scroll_layer_create(bounds);	
	window_set_fullscreen(window, true);	
	window_set_background_color(window, GColorBlack);
		
	// This binds the scroll layer to the window so that up and down map to scrolling
	// You may use scroll_layer_set_callbacks to add or override interactivity
	scroll_layer_set_click_config_onto_window(scroll_layer, scroll_window);
	
	// Initialize the text layer
	text_layer = text_layer_create(max_text_bounds);
	text_layer_set_text_color(text_layer, GColorWhite);
	text_layer_set_background_color(text_layer, GColorBlack);
	text_layer_set_text(text_layer, cheat_sheet[current_image]);
	
	// Change the font to a nice readable one
	// This is system font; you can inspect pebble_fonts.h for all system fonts
	// or you can take a look at feature_custom_font to add your own font
	text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
	
	// Trim text layer and scroll content to fit text box
	GSize max_size = text_layer_get_content_size(text_layer);
	//text_layer_set_size(text_layer, max_size);
	text_layer_set_size(text_layer, GSize(max_size.w, max_size.h + vert_text_layer_padding));
	scroll_layer_set_content_size(scroll_layer, GSize(bounds.size.w, max_size.h + vert_scroll_text_padding));
	
	//scroll_layer_set_shadow_hidden(scroll_layer, true);

	// Add the layers for display
	scroll_layer_add_child(scroll_layer, text_layer_get_layer(text_layer));	
	layer_add_child(window_layer, scroll_layer_get_layer(scroll_layer));	
}

static void scroll_window_unload(Window *window){
	window_destroy(scroll_window);
	text_layer_destroy(text_layer);
	scroll_layer_destroy(scroll_layer);		
}

static void select_click_handler(ClickRecognizerRef recognizer, Window *window) {	
	scroll_window = window_create();
	window_set_window_handlers(scroll_window, (WindowHandlers) {
		.load = scroll_window_load,
		.unload = scroll_window_unload,
	});
	window_stack_push(scroll_window, true /* Animated */);
}

static void config_provider(Window *window) {	
	window_single_click_subscribe(BUTTON_ID_UP, (ClickHandler) up_click_handler);
	window_single_click_subscribe(BUTTON_ID_SELECT, (ClickHandler) select_click_handler);
	window_single_click_subscribe(BUTTON_ID_DOWN, (ClickHandler) down_click_handler);
}

static void window_load(Window *window) {
	window_layer = window_get_root_layer(window);
	GRect bounds = layer_get_frame(window_layer);
	
	image_locations[0] = GRect(0, -IMAGE_SIZE_X, IMAGE_SIZE_X, IMAGE_SIZE_Y);
	image_locations[1] = GRect(0, 0, IMAGE_SIZE_X, IMAGE_SIZE_X);
	image_locations[2] = GRect(0, IMAGE_SIZE_X, IMAGE_SIZE_X, IMAGE_SIZE_Y);
	
	load_up_image(&image_1, (uint32_t)hieroglyph[0], &image_layer_1, bounds);
}

static void window_unload(Window *window) {
	gbitmap_destroy(image_1);
	gbitmap_destroy(image_2);
	bitmap_layer_destroy(image_layer_1);
	bitmap_layer_destroy(image_layer_2);
	
	layer_destroy(window_layer);
	//window_destroy(window);	
	
	property_animation_destroy(property_animation_1);
	property_animation_destroy(property_animation_2);
}

void init(void) {
	window = window_create();
	window_set_window_handlers(window, (WindowHandlers) {
		.load = window_load,
		.unload = window_unload,
	});
	window_set_background_color(window, GColorBlack);
	window_set_fullscreen(window, true);
	window_set_click_config_provider(window, (ClickConfigProvider) config_provider);
	window_stack_push(window, true /* Animated */);		
}

void deinit(void) {

}

int main(void) {
	  init();
	  app_event_loop();
	  deinit();
}
