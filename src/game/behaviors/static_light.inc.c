void bhv_static_light_init(void) {
    o->oLightColor = o->oBehParams & 0xFFFFFF00;
    o->oLightConstantFalloff = (s16)(o->oBehParams & 0x000000FF);
}