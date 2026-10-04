
void FUN_00556352(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int extraout_ECX;
  undefined4 uVar5;
  int unaff_EBP;
  undefined4 *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  
  FUN_00634c24();
  iVar3 = *(int *)(unaff_EBP + 8);
  if ((0x5c < iVar3) || (iVar3 < 0x5a)) {
    puVar8 = &DAT_006f5608;
    puVar7 = &DAT_006f5614;
    iVar3 = *(int *)(DAT_006f2a08 + 0x48);
LAB_0055657f:
    (**(code **)(iVar3 + 0x2c))(puVar7,puVar8,0,0);
    goto LAB_00556582;
  }
  if (iVar3 == 0x5b) {
    uVar5 = *(undefined4 *)(extraout_ECX + 0xf0);
  }
  else {
    uVar5 = *(undefined4 *)(extraout_ECX + 0xf4);
  }
  iVar3 = iVar3 + -0x5a;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
  if ((iVar3 < 0) || (8 < iVar3)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(extraout_ECX + 0x14c + iVar3 * 4) + 0x194;
  }
  if (iVar3 == 0) goto LAB_00556582;
  if (*(int *)(iVar3 + 0x14) != 0) {
    puVar8 = &DAT_006f55c0;
    puVar7 = &DAT_006f55cc;
    iVar3 = *(int *)(DAT_006f2a08 + 0x48);
    goto LAB_0055657f;
  }
  FUN_00429c21();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar2 = FUN_004e1c79(*(undefined4 *)(extraout_ECX + 0xe4),unaff_EBP + -0x2c);
  if (cVar2 == '\0') {
    FUN_005547b8(0);
  }
  else {
    if (*(int *)(iVar3 + 0x10) == 0) {
LAB_005564c8:
      iVar4 = *(int *)(DAT_006f2a08 + 0x48);
LAB_005564d4:
      puVar8 = &DAT_006f5518;
      puVar7 = &DAT_006f5524;
    }
    else {
      if (*(int *)(iVar3 + 0x18) == 0) {
        if (*(int *)(iVar3 + 0x24) != -1) goto LAB_00556539;
        iVar4 = *(int *)(DAT_006f2a08 + 0x48);
        if (*(int *)(iVar3 + 0x1c) <= *(int *)(unaff_EBP + -0x20)) {
          iVar3 = (**(code **)(iVar4 + 0x2c))(&DAT_006f5554,&DAT_006f5548,2,0);
          if (iVar3 == 4) {
            FUN_004f1b96(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(extraout_ECX + 0xe4));
LAB_00556526:
            FUN_005dac30(0x10,extraout_ECX,*(undefined4 *)(unaff_EBP + 8));
          }
          goto LAB_00556559;
        }
        goto LAB_005564d4;
      }
      if (*(int *)(iVar3 + 0x24) == -1) {
        if (*(int *)(iVar3 + 0x1c) <= *(int *)(unaff_EBP + -0x20)) {
          if (*(int *)(extraout_ECX + 0xe4) == -1) {
            iVar3 = 0;
          }
          else {
            FUN_00425db3(*(int *)(extraout_ECX + 0xe4));
            iVar3 = FUN_00410315();
          }
          if (*(int *)(unaff_EBP + -0x10) <= iVar3) {
            iVar3 = (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x2c))
                              (&DAT_006f550c,&DAT_006f5500,2,0);
            if (iVar3 == 4) {
              FUN_005547b8(0);
              puVar6 = (undefined4 *)(extraout_ECX + 0x14c);
              *(undefined4 *)(unaff_EBP + -0x10) = 9;
              do {
                (**(code **)(*(int *)*puVar6 + 0x160))(0);
                puVar6 = puVar6 + 1;
                piVar1 = (int *)(unaff_EBP + -0x10);
                *piVar1 = *piVar1 + -1;
              } while (*piVar1 != 0);
              cVar2 = FUN_004f1b96(*(undefined4 *)(unaff_EBP + 8),
                                   *(undefined4 *)(extraout_ECX + 0xe4));
              if (cVar2 != '\0') {
                FUN_005566f5(*(undefined4 *)(extraout_ECX + 0xe4),
                             *(undefined4 *)(extraout_ECX + 0xe8));
                goto LAB_00556526;
              }
            }
            goto LAB_00556559;
          }
        }
        goto LAB_005564c8;
      }
LAB_00556539:
      puVar8 = &DAT_006f55a8;
      puVar7 = &DAT_006f55b4;
      iVar4 = *(int *)(DAT_006f2a08 + 0x48);
    }
    (**(code **)(iVar4 + 0x2c))(puVar7,puVar8,0,0);
  }
LAB_00556559:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_00556582:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

