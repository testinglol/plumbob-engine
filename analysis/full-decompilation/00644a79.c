
void FUN_00644a79(void)

{
  if ((DAT_00703afc == 1) || ((DAT_00703afc == 0 && (DAT_006daae4 == 1)))) {
    FUN_00644ab2(0xfc);
    if (DAT_00703d58 != (code *)0x0) {
      (*DAT_00703d58)();
    }
    FUN_00644ab2(0xff);
  }
  return;
}

