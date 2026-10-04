
undefined4 * FUN_60019910(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)FUN_600021ef(0xdc);
  if (puVar1 != (undefined4 *)0x0) {
    puVar3 = puVar1;
    for (iVar2 = 0x37; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *puVar1 = 0x464e5446;
    puVar1[1] = 0xdc;
    puVar1[2] = 300;
    puVar1[3] = puVar1[3] | 1;
    puVar1[3] = puVar1[3] | 2;
    puVar1[3] = puVar1[3] & 0xfffffff3;
    puVar1[3] = puVar1[3] & 0xffffffcf;
    puVar1[3] = puVar1[3] | 0x40;
    puVar1[3] = puVar1[3] | 0x80;
    puVar1[3] = puVar1[3] & 0xfffffeff;
    puVar1[3] = puVar1[3] & 0xfffffdff;
    puVar1[3] = puVar1[3] | 0x400;
    puVar1[3] = puVar1[3] & 0xfffff7ff;
    puVar1[3] = puVar1[3] | 0x1000;
    puVar1[3] = puVar1[3] | 0x2000;
    puVar1[3] = puVar1[3] & 0xffffbfff;
    puVar1[3] = puVar1[3] | 0x8000;
    puVar1[3] = puVar1[3] | 0x20000;
    puVar1[4] = 0x10;
    puVar1[5] = 0;
    puVar1[6] = 100;
    puVar1[7] = 0x2e66666e;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[0xf] = DAT_600b8378;
    *(undefined1 *)(puVar1 + 0x10) = DAT_600b837c;
    *(undefined1 *)(puVar1 + 0x11) = DAT_600b8328;
    *(undefined1 *)(puVar1 + 0x13) = DAT_600b8328;
    *(undefined1 *)(puVar1 + 0x15) = DAT_600b8328;
    puVar1[0x1f] = s_Gerry_Shaw_600b836c._0_4_;
    puVar1[0x20] = s_Gerry_Shaw_600b836c._4_4_;
    *(undefined2 *)(puVar1 + 0x21) = s_Gerry_Shaw_600b836c._8_2_;
    *(char *)((int)puVar1 + 0x86) = s_Gerry_Shaw_600b836c[10];
    puVar1[0x27] = DAT_600b8364;
    *(undefined1 *)(puVar1 + 0x28) = DAT_600b8368;
    puVar1[0x29] = DAT_600b8360;
    puVar1[0x2b] = DAT_600b8360;
    puVar1[0x2f] = s_PC_Font_File_600b8350._0_4_;
    puVar1[0x30] = s_PC_Font_File_600b8350._4_4_;
    puVar1[0x31] = s_PC_Font_File_600b8350._8_4_;
    *(char *)(puVar1 + 0x32) = s_PC_Font_File_600b8350[0xc];
  }
  return puVar1;
}

