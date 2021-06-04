void bhv_static_light_init(void) {
    o->oLightColor = (o->oBehParams & 0xFFFF0000) + ((o->oBehParams & 0x000000FF) << 8);
    o->oLightQuadraticFalloff = (s16)((o->oBehParams & 0x0000FF00) >> 8);
}