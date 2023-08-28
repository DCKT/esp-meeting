void writeScreen(const char *s) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_7x14B_tr);
  u8g2.drawStr(0,20, s);
  u8g2.sendBuffer();
}
