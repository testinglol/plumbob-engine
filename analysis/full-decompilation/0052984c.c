
bool FUN_0052984c(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  void *pvVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  int extraout_ECX;
  int iVar9;
  int iVar10;
  int unaff_EBP;
  int *piVar11;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x24) = extraout_ECX;
  FUN_005a5631(0xf3f,unaff_EBP + -0x20,4);
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    iVar10 = *(int *)(extraout_ECX + 0xfc);
    iVar7 = *(int *)(extraout_ECX + 0xf8);
    piVar11 = (int *)(extraout_ECX + 0xf8);
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    if ((iVar10 - iVar7) / 0xc != 0) {
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      do {
        FUN_0046f824(unaff_EBP + -0x14c,0,0x104);
        iVar10 = *piVar11;
        *(undefined ***)(unaff_EBP + -0x158) = &PTR_FUN_006664e8;
        FUN_0046f8cb(*(undefined4 *)(*(int *)(unaff_EBP + -0x10) + iVar10));
        uVar3 = FUN_004dedc6(unaff_EBP + -0x158,(-(*(int *)(DAT_006e486c + 0x34) != 1) & 2U) + 5);
        *(undefined4 *)(unaff_EBP + -0x18) = uVar3;
        cVar2 = FUN_00529ba3(uVar3);
        if (cVar2 != '\0') {
          piVar4 = (int *)(**(code **)(**(int **)(unaff_EBP + -0x20) + 0x94))();
          *(int **)(unaff_EBP + -0x48) = piVar4;
          if (piVar4 == (int *)0x0) {
            if (*(int **)(unaff_EBP + -0x18) == (int *)0x0) break;
            puVar8 = (undefined4 *)**(int **)(unaff_EBP + -0x18);
          }
          else {
            (**(code **)(*piVar4 + 0x68))(DAT_006f2a64);
            iVar10 = *(int *)(unaff_EBP + -0x18);
            if (*(int *)(iVar10 + 0x1c) < 0x24) {
              iVar7 = *(int *)(iVar10 + 0x14);
              *(int *)(unaff_EBP + -0x44) = iVar7;
              iVar1 = *(int *)(iVar10 + 0x18);
              *(int *)(unaff_EBP + -0x40) = iVar1;
              *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(iVar10 + 0x1c);
              iVar10 = *(int *)(iVar10 + 0x20);
              *(int *)(unaff_EBP + -0x38) = iVar10;
              iVar9 = ((iVar1 - iVar10) + 0x24) / 2 + 4;
              iVar10 = ((iVar7 - *(int *)(unaff_EBP + -0x3c)) + 0x24) / 2 + 4;
              *(int *)(unaff_EBP + -0x30) = iVar1 + iVar9;
              piVar4 = *(int **)(unaff_EBP + -0x48);
              *(int *)(unaff_EBP + -0x34) = iVar10 + iVar7;
              *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x3c) + iVar10;
              *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x38) + iVar9;
            }
            else {
              *(undefined4 *)(unaff_EBP + -0x44) = 0;
              *(undefined4 *)(unaff_EBP + -0x40) = 0;
              *(undefined4 *)(unaff_EBP + -0x3c) = 0x24;
              *(undefined4 *)(unaff_EBP + -0x38) = 0x24;
              *(undefined4 *)(unaff_EBP + -0x34) = 4;
              *(undefined4 *)(unaff_EBP + -0x30) = 4;
              *(undefined4 *)(unaff_EBP + -0x2c) = 0x28;
              *(undefined4 *)(unaff_EBP + -0x28) = 0x28;
            }
            cVar2 = (**(code **)(*piVar4 + 0x20))(0x10);
            if (cVar2 != '\0') {
              iVar10 = 4;
              do {
                (**(code **)(*piVar4 + 0x9c))
                          (*(undefined4 *)(unaff_EBP + -0x18),unaff_EBP + -0x44,unaff_EBP + -0x34,0)
                ;
                *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + 0x2d;
                *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 0x2d;
                iVar10 = iVar10 + -1;
              } while (iVar10 != 0);
              (**(code **)(*piVar4 + 0x24))(0x10);
            }
            if (*(int *)(unaff_EBP + -0x18) != 0) {
              FUN_005e357a();
            }
            FUN_0052a3f2(unaff_EBP + -0x18);
            pvVar5 = operator_new(0x194);
            *(void **)(unaff_EBP + -0x48) = pvVar5;
            *(undefined4 *)(unaff_EBP + -4) = 0;
            if (pvVar5 == (void *)0x0) {
              piVar6 = (int *)0x0;
            }
            else {
              piVar6 = (int *)FUN_005e372a();
            }
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            *(int **)(unaff_EBP + -0x14) = piVar6;
            if (piVar6 != (int *)0x0) {
              (**(code **)(*piVar6 + 0x19c))(piVar4,4,1);
              *(undefined1 *)(*(int *)(unaff_EBP + -0x14) + 0x16b) = 1;
              *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xf8) = 1;
              *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xf4) = 1;
              iVar7 = DAT_006d74f0;
              iVar10 = *(int *)(unaff_EBP + -0x14);
              if (DAT_006d74f0 == 0) {
                *(undefined4 *)(iVar10 + 0x154) = 0;
              }
              else {
                *(undefined4 *)(iVar10 + 0x154) = 6;
                *(int *)(iVar10 + 0x158) = iVar7;
              }
              piVar4 = *(int **)(unaff_EBP + -0x24);
              *(undefined1 *)(iVar10 + 0x16c) = 0;
              (**(code **)(*piVar4 + 0x20))(*(undefined4 *)(unaff_EBP + -0x14));
              FUN_00524c70(unaff_EBP + -0x14);
              piVar4 = (int *)(*(int *)(unaff_EBP + -0x10) + *piVar11);
              iVar10 = piVar4[1] - *piVar4;
              do {
                iVar7 = iVar10;
                iVar10 = iVar7 + -1;
                if (iVar10 < 0) goto LAB_00529b0f;
                cVar2 = *(char *)(*piVar4 + iVar10);
              } while ((cVar2 != '/') && (cVar2 != '\\'));
              if (iVar10 != -1) {
                FUN_00406466(0,iVar7);
              }
LAB_00529b0f:
              iVar7 = piVar4[1] - *piVar4;
              iVar10 = iVar7;
              do {
                iVar10 = iVar10 + -1;
                if (iVar10 < 0) goto LAB_00529b38;
              } while (*(char *)(*piVar4 + iVar10) != '.');
              if (iVar10 != -1) {
                FUN_00406466(iVar10,iVar7 - iVar10);
              }
              goto LAB_00529b38;
            }
            if (piVar4 == (int *)0x0) break;
            puVar8 = (undefined4 *)*piVar4;
          }
          (*(code *)*puVar8)(1);
          break;
        }
        FUN_0052a3c2(*(int *)(unaff_EBP + -0x10) + *piVar11);
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + -1;
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + -0xc;
        if (*(undefined4 **)(unaff_EBP + -0x18) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(unaff_EBP + -0x18))(1);
        }
LAB_00529b38:
        iVar10 = *(int *)(extraout_ECX + 0xfc);
        iVar7 = *piVar11;
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0xc;
      } while (*(uint *)(unaff_EBP + -0x1c) < (uint)((iVar10 - iVar7) / 0xc));
    }
    if (*(undefined4 **)(unaff_EBP + -0x20) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(unaff_EBP + -0x20))(1);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return (*(int *)(*(int *)(unaff_EBP + -0x24) + 0xf0) -
          *(int *)(*(int *)(unaff_EBP + -0x24) + 0xec) & 0xfffffffcU) != 0;
}

