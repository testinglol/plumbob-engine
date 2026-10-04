
void FUN_005f51e0(void)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  pvVar3 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x14) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_005e372a();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int **)(unaff_EBP + -0x10) = piVar4;
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x9c))(*(undefined4 *)(unaff_EBP + 0xc));
    (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x19c))(0,4,1);
    FUN_005e4071(extraout_ECX[0x45]);
    *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xf8) = 1;
    *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xf4) = 1;
    FUN_005e46f0(0);
    iVar5 = (extraout_ECX[0x21] - *(int *)(extraout_ECX[0x39] + 0x20)) - extraout_ECX[0x1f];
    (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x60))(0,0,iVar5,extraout_ECX[0x3c]);
    iVar1 = *(int *)(unaff_EBP + -0x10);
    iVar2 = extraout_ECX[0x3c];
    *(undefined4 *)(iVar1 + 0x160) = 1;
    *(undefined4 *)(iVar1 + 0x11c) = 0;
    *(undefined4 *)(iVar1 + 0x120) = 0;
    *(int *)(iVar1 + 0x124) = iVar5;
    *(int *)(iVar1 + 0x128) = iVar2;
    *(undefined4 *)(iVar1 + 0x164) = 0;
    FUN_005e4a66(1);
    (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x10));
    iVar1 = *(int *)(unaff_EBP + 8);
    piVar4 = extraout_ECX + 0x35;
    FUN_005f5ad3(*piVar4 + iVar1 * 4,unaff_EBP + -0x10);
    iVar2 = extraout_ECX[0x3e];
    if ((iVar2 != -1) && (iVar1 <= iVar2)) {
      extraout_ECX[0x3e] = iVar2 + 1;
    }
    if ((int *)extraout_ECX[0x38] != (int *)0x0) {
      iVar1 = *(int *)extraout_ECX[0x38];
      if (extraout_ECX[0x3a] < extraout_ECX[0x36] - *piVar4 >> 2) {
        (**(code **)(iVar1 + 0x94))();
        (**(code **)(*(int *)extraout_ECX[0x38] + 0x1ac))(0);
        (**(code **)(*(int *)extraout_ECX[0x38] + 0x1b0))
                  ((extraout_ECX[0x36] - *piVar4 >> 2) - extraout_ECX[0x3a]);
        (**(code **)(*(int *)extraout_ECX[0x38] + 0x1a8))(extraout_ECX[0x3b]);
        (**(code **)(*(int *)extraout_ECX[0x38] + 0x1d4))(extraout_ECX[0x3a]);
      }
      else {
        (**(code **)(iVar1 + 0x98))();
      }
    }
    FUN_005f50ff();
    (**(code **)(*extraout_ECX + 0x168))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

