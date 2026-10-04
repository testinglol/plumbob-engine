
void FUN_0053d4b1(void)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar4 = 0;
  do {
    *(char *)(unaff_EBP + -0x10) = (char)uVar4;
    (&DAT_006f4c20)[uVar4] = 0;
    (&DAT_006f4d20)[uVar4] = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    (&DAT_006f4e20)[uVar4] = 0;
    (&DAT_006f4b20)[uVar4] = 0;
    (&DAT_006f4a20)[uVar4] = 0;
    if ((uVar4 & 1) != 0) {
      (&DAT_006f4e20)[uVar4] = 2;
      (&DAT_006f4d20)[uVar4] = (&DAT_006f4d20)[uVar4] | 4;
      (&DAT_006f4c20)[uVar4] = (&DAT_006f4c20)[uVar4] | 8;
    }
    if ((uVar4 & 2) != 0) {
      (&DAT_006f4e20)[uVar4] = (&DAT_006f4e20)[uVar4] | 4;
      (&DAT_006f4d20)[uVar4] = (&DAT_006f4d20)[uVar4] | 8;
      (&DAT_006f4c20)[uVar4] = (&DAT_006f4c20)[uVar4] | 1;
    }
    if ((uVar4 & 4) != 0) {
      (&DAT_006f4e20)[uVar4] = (&DAT_006f4e20)[uVar4] | 8;
      (&DAT_006f4d20)[uVar4] = (&DAT_006f4d20)[uVar4] | 1;
      (&DAT_006f4c20)[uVar4] = (&DAT_006f4c20)[uVar4] | 2;
    }
    if ((uVar4 & 8) != 0) {
      (&DAT_006f4e20)[uVar4] = (&DAT_006f4e20)[uVar4] | 1;
      (&DAT_006f4d20)[uVar4] = (&DAT_006f4d20)[uVar4] | 2;
      (&DAT_006f4c20)[uVar4] = (&DAT_006f4c20)[uVar4] | 4;
    }
    if ((uVar4 & 0x10) != 0) {
      (&DAT_006f4e20)[uVar4] = (&DAT_006f4e20)[uVar4] | 0x20;
      (&DAT_006f4d20)[uVar4] = (&DAT_006f4d20)[uVar4] | 0x40;
      (&DAT_006f4c20)[uVar4] = (&DAT_006f4c20)[uVar4] | 0x80;
    }
    if ((uVar4 & 0x20) != 0) {
      (&DAT_006f4e20)[uVar4] = (&DAT_006f4e20)[uVar4] | 0x40;
      (&DAT_006f4d20)[uVar4] = (&DAT_006f4d20)[uVar4] | 0x80;
      (&DAT_006f4c20)[uVar4] = (&DAT_006f4c20)[uVar4] | 0x10;
    }
    if ((uVar4 & 0x40) != 0) {
      (&DAT_006f4e20)[uVar4] = (&DAT_006f4e20)[uVar4] | 0x80;
      (&DAT_006f4d20)[uVar4] = (&DAT_006f4d20)[uVar4] | 0x10;
      (&DAT_006f4c20)[uVar4] = (&DAT_006f4c20)[uVar4] | 0x20;
    }
    if ((uVar4 & 0x80) != 0) {
      (&DAT_006f4e20)[uVar4] = (&DAT_006f4e20)[uVar4] | 0x10;
      (&DAT_006f4d20)[uVar4] = (&DAT_006f4d20)[uVar4] | 0x20;
      (&DAT_006f4c20)[uVar4] = (&DAT_006f4c20)[uVar4] | 0x40;
    }
    cVar2 = FUN_0053d679();
    if (cVar2 != '\0') {
      bVar1 = *(byte *)(unaff_EBP + -0x10);
      if (((bVar1 & 1) != 0) && ((bVar1 & 0xfa) != 0)) {
        (&DAT_006f4b20)[uVar4] = 1;
      }
      if (((bVar1 & 2) != 0) && ((bVar1 & 0xf5) != 0)) {
        (&DAT_006f4b20)[uVar4] = 1;
      }
      if (((bVar1 & 8) != 0) && ((bVar1 & 0xf5) != 0)) {
        (&DAT_006f4b20)[uVar4] = 1;
      }
      if (((bVar1 & 8) != 0) && ((bVar1 & 0xf5) != 0)) {
        (&DAT_006f4b20)[uVar4] = 1;
      }
      if (((bVar1 & 0x10) != 0) && ((bVar1 & 0xaf) != 0)) {
        (&DAT_006f4b20)[uVar4] = 1;
      }
      if (((bVar1 & 0x40) != 0) && ((bVar1 & 0xaf) != 0)) {
        (&DAT_006f4b20)[uVar4] = 1;
      }
      if (((bVar1 & 0x80) != 0) && ((bVar1 & 0x5f) != 0)) {
        (&DAT_006f4b20)[uVar4] = 1;
      }
      if (((bVar1 & 0x20) != 0) && ((bVar1 & 0x5f) != 0)) {
        (&DAT_006f4b20)[uVar4] = 1;
      }
      iVar3 = FUN_0053d6a1(*(undefined4 *)(unaff_EBP + -0x10));
      if (iVar3 == 1) {
        (&DAT_006f4a20)[uVar4] = 1;
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    uVar4 = uVar4 + 1;
  } while ((int)uVar4 < 0x100);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

