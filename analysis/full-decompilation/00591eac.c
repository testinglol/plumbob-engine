
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00591eac(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  (**(code **)(*extraout_ECX + 0x104))(*(undefined4 *)(unaff_EBP + 8));
  iVar3 = **(int **)(unaff_EBP + 0xc);
  iVar1 = (*(int **)(unaff_EBP + 0xc))[1];
  if (iVar1 != iVar3 && -1 < iVar1 - iVar3) {
    iVar1 = FUN_00636450(iVar3,0x3b);
    *(int *)(unaff_EBP + 0xc) = iVar1;
    if (iVar1 != 0) {
      FUN_005b86cf(iVar3,iVar1 - iVar3);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar3 = *(int *)(unaff_EBP + 0xc) + 1;
      uVar2 = FUN_00635f62(iVar3);
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
      iVar3 = FUN_00636450(iVar3,0x3b);
      if (iVar3 != 0) {
        uVar2 = FUN_00635f62(iVar3 + 1);
        *(undefined4 *)(unaff_EBP + 0xc) = uVar2;
        *(float *)(unaff_EBP + -0x14) = (float)*(int *)(unaff_EBP + 0xc) * _DAT_00666a24;
        iVar3 = FUN_00636450(iVar3 + 1,0x3b);
        if (iVar3 != 0) {
          uVar2 = FUN_00635f62(iVar3 + 1);
          *(undefined4 *)(unaff_EBP + 0xc) = uVar2;
          *(float *)(unaff_EBP + -0x1c) = (float)*(int *)(unaff_EBP + 0xc) * _DAT_00666a24;
          iVar3 = FUN_00636450(iVar3 + 1,0x3b);
          if (iVar3 != 0) {
            uVar2 = FUN_00635f62(iVar3 + 1);
            *(undefined4 *)(unaff_EBP + 0xc) = uVar2;
            *(float *)(unaff_EBP + -0x10) = (float)*(int *)(unaff_EBP + 0xc) * _DAT_00666a24;
            iVar3 = FUN_00636450(iVar3 + 1,0x3b);
            if (iVar3 != 0) {
              uVar2 = FUN_00635f62(iVar3 + 1);
              *(undefined4 *)(unaff_EBP + 0xc) = uVar2;
              iVar3 = FUN_00636450(iVar3 + 1,0x3b);
              if (iVar3 != 0) {
                uVar2 = FUN_00635f62(iVar3 + 1);
                *(undefined4 *)(unaff_EBP + -0x20) = uVar2;
                iVar3 = FUN_00636450(iVar3 + 1,0x3b);
                if (iVar3 != 0) {
                  uVar2 = FUN_00635f62(iVar3 + 1);
                  iVar3 = (**(code **)(*extraout_ECX + 0xf0))(unaff_EBP + -0x2c);
                  if (iVar3 != 0) {
                    uVar4 = (**(code **)(*extraout_ECX + 0x34))();
                    iVar3 = FUN_005a08e3(iVar3,*(undefined4 *)(unaff_EBP + -0x18),unaff_EBP + -0x14,
                                         unaff_EBP + -0x10,uVar4);
                    if (iVar3 != 0) {
                      *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(unaff_EBP + -0x1c);
                      FUN_0042004f();
                      uVar4 = *(undefined4 *)(unaff_EBP + 0xc);
                      *(undefined4 *)(iVar3 + 0x7c) = uVar2;
                      *(undefined4 *)(iVar3 + 0x40) = uVar4;
                      *(undefined4 *)(iVar3 + 0x78) = *(undefined4 *)(unaff_EBP + -0x20);
                      *(undefined4 *)(iVar3 + 0x5c) = DAT_006d043c;
                      **(int **)(unaff_EBP + 8) = iVar3;
                    }
                  }
                }
              }
            }
          }
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

