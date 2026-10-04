
void FUN_005fa184(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  size_t _Size;
  int iVar6;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar7;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc8;
  iVar4 = extraout_ECX[0xf];
  piVar7 = extraout_ECX + 0xf;
  *(int **)(unaff_EBP + -0x2c) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(int **)(unaff_EBP + -0x34) = piVar7;
  *(undefined ***)(unaff_EBP + -0x38) = &PTR_LAB_00669c88;
  (**(code **)(iVar4 + 4))();
  piVar1 = (int *)extraout_ECX[0x2f];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (((*piVar1 == 0) || (piVar1 == (int *)0x0)) || (piVar1[0xd] != 0)) goto LAB_005fa1c7;
  piVar1[0xd] = 1;
  (**(code **)(*(int *)extraout_ECX[0x20] + 0x10))
            ((int *)extraout_ECX[0x20],unaff_EBP + -0x24,unaff_EBP + -0x30);
  iVar4 = extraout_ECX[0x2f];
  uVar5 = *(uint *)(unaff_EBP + -0x24);
  if (*(uint *)(iVar4 + 0xc) < uVar5) {
    if (*(int *)(iVar4 + 8) + *(uint *)(iVar4 + 0xc) <= uVar5) {
      piVar7 = *(int **)(unaff_EBP + -0x34);
      goto LAB_005fa224;
    }
LAB_005fa630:
    piVar7 = *(int **)(unaff_EBP + -0x34);
  }
  else {
LAB_005fa224:
    if ((*(int *)(iVar4 + 0x1c) == 0) || (*(int *)(iVar4 + 0x20) != 0)) {
      uVar2 = *(uint *)(iVar4 + 0x10);
      if (uVar5 < uVar2) {
        *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + (*(int *)(iVar4 + 4) - uVar2) + uVar5;
        piVar7 = *(int **)(unaff_EBP + -0x34);
      }
      else {
        *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + (uVar5 - uVar2);
      }
      *(undefined4 *)(extraout_ECX[0x2f] + 0x10) = *(undefined4 *)(unaff_EBP + -0x24);
      iVar4 = extraout_ECX[0x2f];
      if ((*(int *)(iVar4 + 0x1c) == 0) || (*(int *)(iVar4 + 0x20) == 0)) {
        iVar4 = (**(code **)(*(int *)extraout_ECX[0x20] + 0x2c))
                          ((int *)extraout_ECX[0x20],*(undefined4 *)(iVar4 + 0xc),
                           *(undefined4 *)(iVar4 + 8),unaff_EBP + -0x20,unaff_EBP + -0x18,
                           unaff_EBP + -0x1c,unaff_EBP + -0x14,0);
        if (iVar4 != 0) goto LAB_005fa630;
        if (*(int *)(unaff_EBP + -0x18) != 0) {
          if (((undefined4 *)extraout_ECX[0x2f])[6] == 0) {
            uVar5 = (**(code **)(**(int **)extraout_ECX[0x2f] + 0x10))
                              (*(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + -0x18)
                              );
            *(uint *)(unaff_EBP + -0x28) = uVar5;
            if (uVar5 < *(uint *)(unaff_EBP + -0x18)) {
              iVar4 = FUN_005d49d6();
              if (iVar4 == 0) {
                if ((char)extraout_ECX[9] == '\0') {
                  *(undefined4 *)(extraout_ECX[0x2f] + 0x1c) = 1;
                  _memset((void *)(uVar5 + *(int *)(unaff_EBP + -0x20)),
                          (-(uint)(*(short *)((int)extraout_ECX + 0xb6) != 8) & 0xffffff80) + 0x80,
                          *(int *)(unaff_EBP + -0x18) - uVar5);
                  iVar4 = extraout_ECX[0x2f];
                  if (*(uint *)(iVar4 + 0xc) < *(uint *)(unaff_EBP + -0x24)) {
                    iVar6 = *(int *)(iVar4 + 4) - *(int *)(unaff_EBP + -0x24);
                  }
                  else {
                    iVar6 = -*(int *)(unaff_EBP + -0x24);
                  }
                  *(uint *)(iVar4 + 0x20) = (iVar6 + *(uint *)(iVar4 + 0xc)) / *(uint *)(iVar4 + 8);
                }
                else {
                  iVar4 = *(int *)(unaff_EBP + -0x20);
                  do {
                    puVar3 = (undefined4 *)extraout_ECX[0x2f];
                    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) - uVar5;
                    iVar4 = iVar4 + uVar5;
                    (**(code **)(*(int *)*puVar3 + 0x14))();
                    uVar5 = (**(code **)(**(int **)extraout_ECX[0x2f] + 0x10))
                                      (iVar4,*(undefined4 *)(unaff_EBP + -0x18));
                    *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + uVar5;
                  } while (uVar5 < *(uint *)(unaff_EBP + -0x18));
                }
              }
              else {
                FUN_005fa650();
              }
            }
            FUN_005f7a3c(*(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + -0x18));
          }
          else {
            _memset(*(void **)(unaff_EBP + -0x20),
                    (-(uint)(*(short *)((int)extraout_ECX + 0xb6) != 8) & 0xffffff80) + 0x80,
                    *(size_t *)(unaff_EBP + -0x18));
          }
        }
        if (*(int *)(unaff_EBP + -0x14) != 0) {
          if (((undefined4 *)extraout_ECX[0x2f])[6] == 0) {
            uVar5 = (**(code **)(**(int **)extraout_ECX[0x2f] + 0x10))
                              (*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x14)
                              );
            *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + uVar5;
            if (uVar5 == 0) {
              (**(code **)(*(int *)extraout_ECX[0x20] + 0x4c))
                        ((int *)extraout_ECX[0x20],*(undefined4 *)(unaff_EBP + -0x20),
                         *(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x1c),
                         *(undefined4 *)(unaff_EBP + -0x14));
              *(undefined4 *)(extraout_ECX[0x2f] + 0x18) = 1;
              (**(code **)(*extraout_ECX + 0xe0))();
              goto LAB_005fa630;
            }
            if (uVar5 < *(uint *)(unaff_EBP + -0x14)) {
              iVar4 = FUN_005d49d6();
              if (iVar4 == 0) {
                if ((char)extraout_ECX[9] == '\0') {
                  if (*(short *)((int)extraout_ECX + 0xb6) == 8) {
                    _Size = *(int *)(unaff_EBP + -0x14) - uVar5;
                    iVar4 = 0x80;
LAB_005fa550:
                    _memset((void *)(uVar5 + *(int *)(unaff_EBP + -0x1c)),iVar4,_Size);
                  }
                  else if (*(short *)((int)extraout_ECX + 0xb6) == 0x10) {
                    _Size = *(int *)(unaff_EBP + -0x14) - uVar5;
                    iVar4 = 0;
                    goto LAB_005fa550;
                  }
                  *(undefined4 *)(extraout_ECX[0x2f] + 0x1c) = 1;
                  iVar4 = extraout_ECX[0x2f];
                  if (*(uint *)(iVar4 + 0xc) < *(uint *)(unaff_EBP + -0x24)) {
                    iVar6 = *(int *)(iVar4 + 4) - *(int *)(unaff_EBP + -0x24);
                  }
                  else {
                    iVar6 = -*(int *)(unaff_EBP + -0x24);
                  }
                  *(uint *)(iVar4 + 0x20) = (iVar6 + *(uint *)(iVar4 + 0xc)) / *(uint *)(iVar4 + 8);
                }
                else {
                  iVar4 = *(int *)(unaff_EBP + -0x1c);
                  do {
                    puVar3 = (undefined4 *)extraout_ECX[0x2f];
                    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) - uVar5;
                    iVar4 = iVar4 + uVar5;
                    (**(code **)(*(int *)*puVar3 + 0x14))();
                    uVar5 = (**(code **)(**(int **)extraout_ECX[0x2f] + 0x10))
                                      (iVar4,*(undefined4 *)(unaff_EBP + -0x14));
                    *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + uVar5;
                  } while (uVar5 < *(uint *)(unaff_EBP + -0x14));
                }
              }
              else {
                FUN_005fa650();
              }
            }
            FUN_005f7a3c(*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x14));
          }
          else {
            _memset(*(void **)(unaff_EBP + -0x1c),
                    (-(uint)(*(short *)((int)extraout_ECX + 0xb6) != 8) & 0xffffff80) + 0x80,
                    *(size_t *)(unaff_EBP + -0x14));
          }
        }
        (**(code **)(*(int *)extraout_ECX[0x20] + 0x4c))
                  ((int *)extraout_ECX[0x20],*(undefined4 *)(unaff_EBP + -0x20),
                   *(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x1c),
                   *(undefined4 *)(unaff_EBP + -0x14));
        *(int *)(extraout_ECX[0x2f] + 0xc) =
             *(int *)(extraout_ECX[0x2f] + 0xc) + *(int *)(unaff_EBP + -0x28);
        iVar4 = extraout_ECX[0x2f];
        if (*(uint *)(iVar4 + 4) <= *(uint *)(iVar4 + 0xc)) {
          *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) - *(uint *)(iVar4 + 4);
        }
        goto LAB_005fa630;
      }
      *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + -1;
      iVar4 = extraout_ECX[0x2f];
      if ((1 < *(int *)(iVar4 + 0x20)) &&
         (iVar4 = (**(code **)(*(int *)extraout_ECX[0x20] + 0x2c))
                            ((int *)extraout_ECX[0x20],*(undefined4 *)(iVar4 + 0xc),
                             *(undefined4 *)(iVar4 + 8),unaff_EBP + -0x20,unaff_EBP + -0x18,
                             unaff_EBP + -0x1c,unaff_EBP + -0x14,0), iVar4 == 0)) {
        _memset(*(void **)(unaff_EBP + -0x20),
                (-(uint)(*(short *)((int)extraout_ECX + 0xb6) != 8) & 0xffffff80) + 0x80,
                *(size_t *)(unaff_EBP + -0x18));
        (**(code **)(*(int *)extraout_ECX[0x20] + 0x4c))
                  ((int *)extraout_ECX[0x20],*(undefined4 *)(unaff_EBP + -0x20),
                   *(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x1c),
                   *(undefined4 *)(unaff_EBP + -0x14));
        piVar1 = (int *)(extraout_ECX[0x2f] + 0xc);
        *piVar1 = *piVar1 + *(int *)(extraout_ECX[0x2f] + 8);
        iVar4 = extraout_ECX[0x2f];
        if (*(uint *)(iVar4 + 4) <= *(uint *)(iVar4 + 0xc)) {
          *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) - *(uint *)(iVar4 + 4);
        }
      }
    }
    else if (*(int *)(iVar4 + 0x18) == 0) {
      *(undefined4 *)(iVar4 + 0x18) = 1;
      (**(code **)(*extraout_ECX + 0xe0))();
      if ((char)extraout_ECX[9] != '\0') {
        *(undefined4 *)(extraout_ECX[0x2f] + 0x34) = 0;
        (**(code **)(*extraout_ECX + 0xdc))((char)extraout_ECX[9],1);
        goto LAB_005fa1c7;
      }
    }
  }
  *(undefined4 *)(extraout_ECX[0x2f] + 0x34) = 0;
LAB_005fa1c7:
  iVar4 = *piVar7;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  (**(code **)(iVar4 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

