
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00605ac8(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  uint uVar5;
  
  FUN_00634c24();
  _DAT_006ff030 = *(undefined4 *)(unaff_EBP + 8);
  if (extraout_ECX[2] == 0) {
    iVar4 = *DAT_006fefd8;
    uVar5 = (-(uint)((extraout_ECX[0x1d] & 0x20000U) != 0) & 0x1fffc00) + 0x400;
    *(uint *)(unaff_EBP + 8) = uVar5;
    cVar1 = (**(code **)(iVar4 + 0x34))();
    if (cVar1 != '\0') {
      *(uint *)(unaff_EBP + 8) = uVar5 | 0x200;
    }
    iVar2 = (**(code **)(*(int *)extraout_ECX[1] + 0x14))
                      ((int *)extraout_ECX[1],*(undefined4 *)(unaff_EBP + 0xc),0,0,
                       *(undefined4 *)(unaff_EBP + 8),&DAT_006fefe0);
    iVar4 = 0;
    if (iVar2 != 0) {
      cVar1 = (**(code **)(*DAT_006fefd8 + 0x34))();
      if (cVar1 != '\0') {
        *(byte *)(unaff_EBP + 9) = *(byte *)(unaff_EBP + 9) & 0xfd;
      }
      *(byte *)(unaff_EBP + 0xb) = *(byte *)(unaff_EBP + 0xb) | 1;
      piVar3 = (int *)extraout_ECX[1];
      goto LAB_00605bc4;
    }
  }
  else {
    iVar4 = *DAT_006fefd8;
    uVar5 = (-(uint)((extraout_ECX[0x38] & 0x20000U) != 0) & 0x1fffc00) + 0x400;
    *(uint *)(unaff_EBP + 8) = uVar5;
    cVar1 = (**(code **)(iVar4 + 0x34))();
    if (cVar1 != '\0') {
      *(uint *)(unaff_EBP + 8) = uVar5 | 0x200;
    }
    iVar2 = (**(code **)(*(int *)extraout_ECX[2] + 0x14))
                      ((int *)extraout_ECX[2],*(undefined4 *)(unaff_EBP + 0xc),0,0,
                       *(undefined4 *)(unaff_EBP + 8),&DAT_006fefe0);
    iVar4 = 0;
    if (iVar2 != 0) {
      cVar1 = (**(code **)(*DAT_006fefd8 + 0x34))();
      if (cVar1 != '\0') {
        *(byte *)(unaff_EBP + 9) = *(byte *)(unaff_EBP + 9) & 0xfd;
      }
      *(byte *)(unaff_EBP + 0xb) = *(byte *)(unaff_EBP + 0xb) | 1;
      piVar3 = (int *)extraout_ECX[2];
LAB_00605bc4:
      iVar4 = (**(code **)(*piVar3 + 0x14))
                        (piVar3,*(undefined4 *)(unaff_EBP + 0xc),0,0,*(undefined4 *)(unaff_EBP + 8),
                         &DAT_006fefe0);
    }
  }
  if (iVar4 == -0x7789fe3e) {
    uVar5 = (**(code **)(*extraout_ECX + 8))();
    piVar3 = DAT_006fefd8;
    if ((char)uVar5 != '\0') {
      iVar4 = extraout_ECX[2];
      *(undefined4 *)(unaff_EBP + 8) = 0x400;
      if (iVar4 == 0) {
        cVar1 = (**(code **)(*piVar3 + 0x34))();
        if (cVar1 != '\0') {
          *(undefined4 *)(unaff_EBP + 8) = 0x600;
        }
        iVar4 = (**(code **)(*(int *)extraout_ECX[1] + 0x14))
                          ((int *)extraout_ECX[1],*(undefined4 *)(unaff_EBP + 0xc),0,0,
                           *(undefined4 *)(unaff_EBP + 8),&DAT_006fefe0);
        if (iVar4 != 0) {
          cVar1 = (**(code **)(*DAT_006fefd8 + 0x34))();
          if (cVar1 != '\0') {
            *(byte *)(unaff_EBP + 9) = *(byte *)(unaff_EBP + 9) & 0xfd;
          }
          *(byte *)(unaff_EBP + 0xb) = *(byte *)(unaff_EBP + 0xb) | 1;
          piVar3 = (int *)extraout_ECX[1];
          goto LAB_00605c83;
        }
      }
      else {
        cVar1 = (**(code **)(*piVar3 + 0x34))();
        if (cVar1 != '\0') {
          *(undefined4 *)(unaff_EBP + 8) = 0x600;
        }
        iVar4 = (**(code **)(*(int *)extraout_ECX[2] + 0x14))
                          ((int *)extraout_ECX[2],*(undefined4 *)(unaff_EBP + 0xc),0,0,
                           *(undefined4 *)(unaff_EBP + 8),&DAT_006fefe0);
        if (iVar4 != 0) {
          cVar1 = (**(code **)(*DAT_006fefd8 + 0x34))();
          if (cVar1 != '\0') {
            *(byte *)(unaff_EBP + 9) = *(byte *)(unaff_EBP + 9) & 0xfd;
          }
          *(byte *)(unaff_EBP + 0xb) = *(byte *)(unaff_EBP + 0xb) | 1;
          piVar3 = (int *)extraout_ECX[2];
LAB_00605c83:
          iVar4 = (**(code **)(*piVar3 + 0x14))
                            (piVar3,*(undefined4 *)(unaff_EBP + 0xc),0,0,
                             *(undefined4 *)(unaff_EBP + 8),&DAT_006fefe0);
          goto LAB_00605c92;
        }
      }
      goto LAB_00605cc1;
    }
  }
  else {
LAB_00605c92:
    if (iVar4 == 0) {
LAB_00605cc1:
      uVar5 = 1;
      goto LAB_00605cc3;
    }
    *(int *)(unaff_EBP + -0x14) = iVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    uVar5 = (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x10))();
  }
  uVar5 = uVar5 & 0xffffff00;
LAB_00605cc3:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

