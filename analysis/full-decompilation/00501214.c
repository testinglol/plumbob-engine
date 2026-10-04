
void FUN_00501214(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int *extraout_ECX;
  int iVar7;
  int unaff_EBP;
  undefined4 uVar8;
  
  FUN_00634c24();
  if (DAT_006f2c10 != '\0') goto LAB_005017c4;
  iVar7 = *(int *)(unaff_EBP + 8);
  DAT_006f2c10 = 1;
  iVar4 = extraout_ECX[0x36];
  *(int *)(unaff_EBP + -0x18) = iVar4;
  iVar3 = FUN_004cf207();
  extraout_ECX[0x36] = iVar3;
  if ((*(uint *)(iVar7 + 0xc) & 0x110) != 0) {
    iVar7 = *extraout_ECX;
    *(bool *)(unaff_EBP + -0x10) = iVar4 != iVar3;
    (**(code **)(iVar7 + 0x168))();
    FUN_005e46f0(0);
    FUN_005e46f0(1);
    if (extraout_ECX[0x36] != 10) {
      if (iVar4 == 10) {
        FUN_005018af(0);
      }
      iVar7 = extraout_ECX[0x4a];
      piVar1 = extraout_ECX + 0x49;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      if (iVar7 - *piVar1 >> 2 != 0) {
        do {
          iVar7 = *(int *)(unaff_EBP + -0x14) * 4;
          if ((*(int *)(iVar7 + *piVar1) != 0) && (iVar4 = FUN_00492d2c(), iVar4 != 0)) {
            uVar8 = 0;
            FUN_00492d2c(0);
            FUN_005e46f0(uVar8);
            piVar5 = (int *)FUN_00492d2c();
            (**(code **)(*piVar5 + 0x98))();
            *(undefined4 *)(iVar7 + *piVar1) = 0;
          }
          iVar7 = extraout_ECX[0x4a];
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        } while (*(uint *)(unaff_EBP + -0x14) < (uint)(iVar7 - *piVar1 >> 2));
      }
      FUN_0052ea87(*piVar1,extraout_ECX[0x4a]);
      iVar7 = extraout_ECX[0x36];
      *(undefined1 *)(unaff_EBP + -0xd) = 0;
      if ((iVar7 != *(int *)(unaff_EBP + -0x18)) ||
         ((iVar7 == 7 && ((*(byte *)(*(int *)(unaff_EBP + 8) + 0xd) & 1) != 0)))) {
        *(undefined1 *)(unaff_EBP + -0xd) = 1;
      }
      iVar7 = FUN_004ce4a9();
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      iVar4 = *(int *)(iVar7 + 8) - *(int *)(iVar7 + 4) >> 2;
      *(int *)(unaff_EBP + -0x18) = iVar4;
      if (0 < iVar4) {
        do {
          cVar2 = FUN_004cbc88(extraout_ECX[0x36]);
          if (cVar2 != '\0') {
            FUN_004cdcd0(*(int *)(iVar7 + 4) + *(int *)(unaff_EBP + -0x14) * 4);
          }
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        } while (*(int *)(unaff_EBP + -0x14) < *(int *)(unaff_EBP + -0x18));
      }
      uVar6 = FUN_00500b95();
      extraout_ECX[0x56] = uVar6;
      if ((extraout_ECX[0x55] < 0) || ((extraout_ECX[0x4a] - *piVar1 & 0xfffffffcU) == 0)) {
        extraout_ECX[0x55] = 0;
      }
      else if ((uint)(extraout_ECX[0x4a] - *piVar1 >> 2) / uVar6 <= (uint)extraout_ECX[0x55]) {
        extraout_ECX[0x55] = ((extraout_ECX[0x4a] - *piVar1 >> 2) - 1U) / uVar6;
      }
      iVar7 = extraout_ECX[0x4a];
      *(undefined1 *)(unaff_EBP + -0xf) = 0;
      if ((iVar7 - *piVar1 & 0xfffffffcU) != 0) {
        if (1 < (uint)(extraout_ECX[0x4a] - *piVar1 >> 2)) {
          iVar7 = extraout_ECX[0x36];
          uVar8 = 0;
          if (iVar7 == 1) {
            uVar8 = 9;
LAB_0050146c:
            FUN_00501ae6(*piVar1,extraout_ECX[0x4a],uVar8);
          }
          else {
            if (iVar7 == 2) {
              uVar8 = 8;
              goto LAB_0050146c;
            }
            if (iVar7 == 4) {
              uVar8 = 5;
              goto LAB_0050146c;
            }
            if (iVar7 == 5) {
              uVar8 = 7;
              goto LAB_0050146c;
            }
            if (iVar7 == 6) {
              uVar8 = 6;
              goto LAB_0050146c;
            }
            if (iVar7 == 8) {
              uVar8 = 3;
              goto LAB_0050146c;
            }
            if (iVar7 == 9) {
              uVar8 = 4;
              goto LAB_0050146c;
            }
            if (iVar7 == 7) goto LAB_0050146c;
          }
          uVar6 = 0;
          if (extraout_ECX[0x4a] - *piVar1 >> 2 != 0) {
            do {
              if ((*(int *)(*piVar1 + uVar6 * 4) != 0) &&
                 (*(int *)(*(int *)(*piVar1 + uVar6 * 4) + 0x28) != 0)) {
                iVar7 = FUN_00492d2c();
                *(uint *)(iVar7 + 8) = uVar6;
              }
              uVar6 = uVar6 + 1;
            } while (uVar6 < (uint)(extraout_ECX[0x4a] - *piVar1 >> 2));
          }
        }
        iVar7 = FUN_004cf20b();
        *(undefined1 *)(unaff_EBP + -0xe) = 0;
        *(undefined4 *)(unaff_EBP + -0x18) = 0xffffffff;
        *(int *)(unaff_EBP + -0x14) = iVar7;
        if (*(char *)(unaff_EBP + -0xd) != '\0') {
          do {
            uVar6 = 0;
            if (extraout_ECX[0x4a] - *piVar1 >> 2 != 0) {
              do {
                if (iVar7 == *(int *)(*piVar1 + uVar6 * 4)) {
                  if ((int)uVar6 / extraout_ECX[0x56] != -1) {
                    extraout_ECX[0x55] = (int)uVar6 / extraout_ECX[0x56];
                    goto LAB_00501520;
                  }
                  break;
                }
                uVar6 = uVar6 + 1;
              } while (uVar6 < (uint)(extraout_ECX[0x4a] - *piVar1 >> 2));
            }
            FUN_004cf45f(*(undefined4 *)*piVar1);
            iVar7 = FUN_004cf20b();
          } while( true );
        }
        uVar6 = 0;
        if (extraout_ECX[0x4a] - *piVar1 >> 2 != 0) {
          do {
            if (iVar7 == *(int *)(*piVar1 + uVar6 * 4)) {
              if (extraout_ECX[0x55] == (int)uVar6 / extraout_ECX[0x56]) goto LAB_00501520;
              iVar7 = *(int *)(unaff_EBP + -0x14);
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < (uint)(extraout_ECX[0x4a] - *piVar1 >> 2));
        }
        goto LAB_0050152c;
      }
      goto LAB_0050173c;
    }
    FUN_005018af(1);
  }
  goto LAB_00501766;
LAB_00501520:
  *(undefined1 *)(unaff_EBP + -0xe) = 1;
  *(int *)(unaff_EBP + -0x18) = (int)uVar6 % extraout_ECX[0x56];
LAB_0050152c:
  iVar7 = *piVar1;
  uVar6 = extraout_ECX[0x4a];
  iVar4 = extraout_ECX[0x55] * extraout_ECX[0x56];
  *(bool *)(unaff_EBP + -0xd) = 0 < iVar4;
  iVar4 = iVar4 * 4;
  *(int *)(unaff_EBP + -0x14) = iVar4;
  if ((uint)(iVar4 + iVar7) < uVar6) {
    FUN_0052ea87(iVar7,*(int *)(unaff_EBP + -0x14) + iVar7);
  }
  uVar6 = extraout_ECX[0x4a];
  iVar7 = extraout_ECX[0x56];
  iVar4 = *piVar1;
  iVar3 = iVar7 * 4;
  *(bool *)(unaff_EBP + -0xf) = 0 < (int)((uVar6 - iVar4) + iVar7 * -4 & 0xfffffffc);
  if ((uint)(iVar4 + iVar3) < uVar6) {
    FUN_0052ea87(iVar4 + iVar3,uVar6);
  }
  iVar7 = extraout_ECX[0x4a];
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  if (iVar7 - *piVar1 >> 2 != 0) {
    do {
      if ((*(int *)(*(int *)(unaff_EBP + -0x14) * 4 + *piVar1) != 0) &&
         (piVar5 = (int *)FUN_00492d2c(), piVar5 != (int *)0x0)) {
        cVar2 = (**(code **)(*extraout_ECX + 0x38))(piVar5);
        if (cVar2 == '\0') {
          (**(code **)(*extraout_ECX + 0x20))(piVar5);
        }
        (**(code **)(*piVar5 + 0x94))();
        if (*(int *)(unaff_EBP + -0x18) == *(int *)(unaff_EBP + -0x14)) {
          if (*(char *)(unaff_EBP + -0x10) != '\0') {
            if (extraout_ECX != (int *)0x0) {
              FUN_005da644(extraout_ECX,3,1,piVar5,0);
            }
            FUN_004ce5de(0x10);
          }
          FUN_005e46f0(*(char *)(unaff_EBP + -0xe) != '\0');
        }
      }
      iVar7 = extraout_ECX[0x4a];
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
    } while (*(uint *)(unaff_EBP + -0x14) < (uint)(iVar7 - *piVar1 >> 2));
  }
  iVar7 = extraout_ECX[0x4a];
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  iVar7 = iVar7 - *piVar1 >> 2;
  FUN_0054821c(iVar7,unaff_EBP + -0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar8 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x24),iVar7,unaff_EBP + -0x18,
                       *(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -0x20) = uVar8;
  iVar7 = extraout_ECX[0x4a];
  uVar6 = 0;
  iVar4 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (iVar7 - iVar4 >> 2 != 0) {
    do {
      if (*(int *)(*piVar1 + uVar6 * 4) != 0) {
        *(uint *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x24) + uVar6 * 4;
        uVar8 = FUN_00492d2c();
        **(undefined4 **)(unaff_EBP + -0x14) = uVar8;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < (uint)(extraout_ECX[0x4a] - *piVar1 >> 2));
  }
  piVar5 = extraout_ECX + 0x56;
  iVar4 = extraout_ECX[0x4a] - *piVar1 >> 2;
  iVar7 = *piVar5;
  *(int *)(unaff_EBP + -0x14) = iVar4;
  if (iVar4 <= iVar7) {
    piVar5 = (int *)(unaff_EBP + -0x14);
  }
  FUN_004ebf01(*(undefined4 *)(unaff_EBP + -0x24),*piVar5);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0048c4c9();
  if (*(char *)(unaff_EBP + -0xd) == '\0') {
LAB_0050173c:
    (**(code **)(*(int *)extraout_ECX[0x3b] + 0x98))();
  }
  else {
    (**(code **)(*(int *)extraout_ECX[0x3b] + 0x94))();
  }
  if (*(char *)(unaff_EBP + -0xf) == '\0') {
    (**(code **)(*(int *)extraout_ECX[0x3c] + 0x98))();
  }
  else {
    (**(code **)(*(int *)extraout_ECX[0x3c] + 0x94))();
  }
LAB_00501766:
  if ((*(byte *)(*(int *)(unaff_EBP + 8) + 0xc) & 4) != 0) {
    cVar2 = FUN_004cf213();
    piVar1 = (int *)extraout_ECX[0x39];
    if ((char)piVar1[0x5a] != cVar2) {
      *(char *)(piVar1 + 0x5a) = cVar2;
      (**(code **)(*piVar1 + 0x168))();
    }
    cVar2 = FUN_004cf22d();
    piVar1 = (int *)extraout_ECX[0x3a];
    if ((char)piVar1[0x5a] != cVar2) {
      *(char *)(piVar1 + 0x5a) = cVar2;
      (**(code **)(*piVar1 + 0x168))();
    }
  }
  DAT_006f2c10 = '\0';
LAB_005017c4:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

