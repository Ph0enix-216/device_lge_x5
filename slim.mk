# Inherit some common CM stuff.
$(call inherit-product, vendor/slim/config/common_full_phone.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)
$(call inherit-product, vendor/slim/config/nfc_enhanced.mk)
$(call inherit-product, device/lge/x5/device_x5.mk)

# Boot animation
TARGET_SCREEN_WIDTH := 540
TARGET_SCREEN_HEIGHT := 960

# Release name
PRODUCT_RELEASE_NAME := LG Volt
PRODUCT_NAME := slim_x5
PRODUCT_MODEL := x5
PRODUCT_DEVICE := x5
PRODUCT_MANUFACTURER := LGE
PRODUCT_BRAND := lge
