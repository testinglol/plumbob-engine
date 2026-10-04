
uint FUN_005fc67e(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar3 = (**(code **)(*extraout_ECX + 0x1c))();
  FUN_005b86bd(uVar3);
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (**(code **)(iVar1 + 0x28))();
  piVar2 = (int *)extraout_ECX[99];
  *(undefined1 *)(extraout_ECX + 0x5f) = 0;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    extraout_ECX[99] = 0;
  }
  piVar2 = (int *)extraout_ECX[0x62];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x34))(piVar2,0,0xc00,0);
    (**(code **)(*(int *)extraout_ECX[0x62] + 8))((int *)extraout_ECX[0x62]);
    PostMessageA(DAT_006fe8cc,0xc01,0,extraout_ECX[0x62]);
    extraout_ECX[0x62] = 0;
  }
  piVar2 = (int *)extraout_ECX[0x61];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    extraout_ECX[0x61] = 0;
  }
  piVar2 = (int *)extraout_ECX[0x60];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    extraout_ECX[0x60] = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar4 = FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4 & 0xffffff00;
}

