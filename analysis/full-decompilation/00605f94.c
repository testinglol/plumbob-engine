
uint FUN_00605f94(void)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  LPCSTR lpOutputString;
  uint uVar6;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar5 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x15d) = 1;
  extraout_ECX[0x60] = *(int *)(iVar5 + 4);
  (**(code **)(*extraout_ECX + 0x14))(unaff_EBP + -0x14);
  _memset(extraout_ECX + 0x1e,0,0x7c);
  extraout_ECX[0x1e] = 0x7c;
  extraout_ECX[0x1f] = 0x21;
  extraout_ECX[0x38] = 0x4218;
  extraout_ECX[0x23] = 1;
  (**(code **)(*DAT_006fe8bc + 0x1c))();
  piVar4 = extraout_ECX + 0x62;
  iVar5 = FUN_005eff44(extraout_ECX,piVar4,extraout_ECX + 99);
  *(int *)(unaff_EBP + 8) = iVar5;
  if (iVar5 == 0) {
    piVar2 = (int *)extraout_ECX[99];
    if (piVar2 == (int *)0x0) {
      piVar4 = (int *)*piVar4;
      *(undefined4 *)(unaff_EBP + 8) = 4;
      iVar5 = (**(code **)(*piVar4 + 0x30))(piVar4,unaff_EBP + 8,extraout_ECX + 1);
LAB_006060bb:
      if (iVar5 == 0) {
        *(undefined1 *)(extraout_ECX + 0x57) = 1;
        uVar6 = 1;
        goto LAB_006060fc;
      }
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x1c) = 4;
      iVar5 = (**(code **)(*piVar2 + 0x30))(piVar2,unaff_EBP + -0x1c,extraout_ECX + 2);
      if (-1 < iVar5) {
        puVar3 = (undefined4 *)extraout_ECX[2];
        iVar5 = (**(code **)*puVar3)(puVar3,&DAT_00677308,extraout_ECX + 1);
        goto LAB_006060bb;
      }
    }
    *(int *)(unaff_EBP + -0x24) = iVar5;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x28) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    *(undefined4 *)(unaff_EBP + -4) = 3;
    uVar6 = (**(code **)(*(int *)(unaff_EBP + -0x28) + 0x10))();
    extraout_ECX[1] = 0;
  }
  else {
    OutputDebugStringA(s_Creating_primary_surface_failed__006d9264);
    uVar1 = *(undefined4 *)(unaff_EBP + 8);
    lpOutputString = (LPCSTR)FUN_005cbdcb(uVar1);
    OutputDebugStringA(lpOutputString);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    uVar6 = (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x10))();
    *piVar4 = 0;
  }
  uVar6 = uVar6 & 0xffffff00;
LAB_006060fc:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

