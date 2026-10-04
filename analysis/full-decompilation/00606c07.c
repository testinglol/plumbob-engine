
undefined4 FUN_00606c07(void)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    FUN_005dbf32();
    FUN_005ddfdc(1);
    (**(code **)(*extraout_ECX + 0x60))(0,0,DAT_006ff078,DAT_006ff07c);
    FUN_004cb21d(DAT_006ff080,DAT_006ff084);
    uVar2 = FUN_005d4956(&DAT_006ccbc8);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    piVar3 = (int *)FUN_005e7743();
    iVar4 = (**(code **)(*piVar3 + 0x24))(0,uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x43] = iVar4;
    FUN_005b8770();
    if (extraout_ECX[0x43] != 0) {
      FUN_004cb21d(DAT_006ff060,DAT_006ff064);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x43]);
    }
    uVar2 = FUN_005d4956(s_Cancel_006c2abc);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    piVar3 = (int *)FUN_005e7743();
    iVar4 = (**(code **)(*piVar3 + 0x24))(0,uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x44] = iVar4;
    FUN_005b8770();
    if (extraout_ECX[0x44] != 0) {
      FUN_004cb21d(DAT_006ff058,DAT_006ff05c);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x44]);
    }
    uVar2 = FUN_005d4956(s_<unknown>_006c8f34);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    piVar3 = (int *)FUN_005e7743();
    iVar4 = (**(code **)(*piVar3 + 0x28))(0,uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x45] = iVar4;
    FUN_005b8770();
    if ((int *)extraout_ECX[0x45] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[0x45] + 0x60))(0,0,DAT_006ff048,DAT_006ff04c);
      FUN_004cb21d(DAT_006ff050,DAT_006ff054);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x45]);
    }
    pvVar5 = operator_new(0x118);
    *(void **)(unaff_EBP + -0x10) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    if (pvVar5 == (void *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_005f4d1c();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x42] = iVar4;
    if (iVar4 != 0) {
      FUN_005f58c2(extraout_ECX[0x47]);
      *(undefined4 *)(extraout_ECX[0x42] + 0xe8) = 0xc;
      (**(code **)(*(int *)extraout_ECX[0x42] + 0x60))(0,0,DAT_006ff068,DAT_006ff06c);
      FUN_004cb21d(DAT_006ff070,DAT_006ff074);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x42]);
    }
    uVar2 = 1;
  }
  else {
    uVar2 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

