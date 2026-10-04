
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0056e0df(void)

{
  float fVar1;
  float fVar2;
  void *pvVar3;
  int iVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (DAT_006f627c == 0) {
    pvVar3 = operator_new(0x11c);
    *(void **)(unaff_EBP + -0x10) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar3 == (void *)0x0) {
      DAT_006f627c = 0;
    }
    else {
      DAT_006f627c = FUN_0056f6bb(*(undefined4 *)(DAT_006e486c + 0x30),_DAT_00666a40,&DAT_006cea94);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  iVar4 = FUN_005cfd9c((undefined4 *)(extraout_ECX + 0x24),0);
  fVar2 = _DAT_006714d0;
  if (-1 < iVar4) {
    *(float *)(unaff_EBP + -0x28) = _DAT_006714d0 * _DAT_00666a54;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0xbe99999a;
    fVar1 = fVar2 * _DAT_006714dc;
    *(undefined4 *)(unaff_EBP + -0x18) = 0xbf800000;
    *(undefined4 *)(unaff_EBP + -0x14) = 0xbf19999a;
    *(float *)(unaff_EBP + -0x24) = fVar1;
    *(float *)(unaff_EBP + -0x20) = fVar2 * _DAT_0066d738;
    FUN_005d0a0d(unaff_EBP + -0x28,unaff_EBP + -0x1c);
  }
  else {
    *(undefined4 *)(extraout_ECX + 0x24) = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return -1 < iVar4;
}

