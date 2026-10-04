
void FUN_004ac916(void)

{
  float fVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 extraout_ECX;
  int iVar7;
  int *piVar8;
  int unaff_EBP;
  int iVar9;
  undefined4 uStack_58;
  undefined4 uStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  
  FUN_00634c24();
  iVar9 = *DAT_006e486c;
  *(undefined4 *)(unaff_EBP + -0x18) = extraout_ECX;
  piVar8 = *(int **)(*(int *)(iVar9 + 0x14) + 0x84);
  iVar9 = *(int *)(iVar9 + 0x14) + 0x84;
  *(int *)(unaff_EBP + -0x1c) = iVar9;
  for (; piVar3 = *(int **)(iVar9 + 4), *(int **)(unaff_EBP + -0x20) = piVar8, piVar8 != piVar3;
      piVar8 = piVar8 + 1) {
    piVar3 = (int *)*piVar8;
    *(char *)(unaff_EBP + -0x14) = (char)piVar3[0x3f];
    cVar2 = *(char *)((int)piVar3 + 0xfe);
    *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)((int)piVar3 + 0xfd);
    *(char *)(unaff_EBP + -0x12) = cVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar4 = *(int *)(*(int *)(unaff_EBP + -0x18) + 0x18);
    *(int *)(unaff_EBP + -0x28) = (int)cVar2;
    if (cVar2 <= iVar4) {
      iStack_48 = 0x4ac98b;
      piVar3 = (int *)(**(code **)(*piVar3 + 0x8c))();
      *(int **)(unaff_EBP + -0x24) = piVar3;
      iStack_48 = 0x4ac997;
      cVar2 = (**(code **)(*piVar3 + 0x70))();
      if (cVar2 != '\0') {
        iStack_48 = 0x4ac9a6;
        iVar4 = FUN_00592961();
        if (iVar4 != 0) {
          iStack_48 = 0x4ac9b8;
          (**(code **)(*piVar3 + 0xac))();
          iStack_48 = 0x4ac9bf;
          puVar5 = (undefined4 *)FUN_0059296f();
          *(undefined4 *)(unaff_EBP + -0x44) = *puVar5;
          *(undefined4 *)(unaff_EBP + -0x40) = puVar5[1];
          *(undefined4 *)(unaff_EBP + -0x3c) = puVar5[2];
          *(undefined4 *)(unaff_EBP + -0x38) = puVar5[3];
          piVar3 = DAT_006e486c;
          if (((*(int *)(unaff_EBP + -0x44) != 0x7fffffff) &&
              (iVar9 = *(int *)(unaff_EBP + -0x3c), *(int *)(unaff_EBP + -0x44) < iVar9)) &&
             (iVar4 = *(int *)(unaff_EBP + -0x38), *(int *)(unaff_EBP + -0x40) < iVar4)) {
            iVar7 = 0;
            *(undefined4 *)(unaff_EBP + -0x10) = 0;
            iStack_48 = 0x4ac9ff;
            iVar6 = (**(code **)(*(int *)piVar3[1] + 0x14))();
            if (iVar6 == 1) {
              *(undefined4 *)(unaff_EBP + -0x10) = 3;
              iVar7 = 1;
            }
            else if (iVar6 == 2) {
              *(undefined4 *)(unaff_EBP + -0x10) = 6;
              iVar7 = 2;
            }
            else if (iVar6 == 3) {
              *(undefined4 *)(unaff_EBP + -0x10) = 0xc;
              iVar7 = 4;
            }
            *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) - iVar7;
            *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + *(int *)(unaff_EBP + -0x10);
            *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x44) - iVar7;
            iVar6 = iVar4 + iVar7 + *(int *)(unaff_EBP + -0x10);
            iStack_48 = unaff_EBP + -0x34;
            iVar9 = iVar9 + iVar7;
            *(int *)(unaff_EBP + -0x3c) = iVar9;
            *(int *)(unaff_EBP + -0x38) = iVar6;
            iStack_4c = 0x4aca4e;
            FUN_00592976();
            iStack_48 = *(undefined4 *)(unaff_EBP + 0xc);
            iVar4 = *(int *)(*(int *)(unaff_EBP + -0x18) + 0x54);
            iStack_4c = *(undefined4 *)(unaff_EBP + -0x28);
            fVar1 = *(float *)(iVar4 + 0x184);
            *(undefined4 **)(unaff_EBP + -0x28) = &uStack_58;
            *(float *)(unaff_EBP + -0x34) = *(float *)(unaff_EBP + -0x34) - fVar1;
            *(float *)(unaff_EBP + -0x30) =
                 *(float *)(unaff_EBP + -0x30) - *(float *)(iVar4 + 0x188);
            *(float *)(unaff_EBP + -0x2c) =
                 *(float *)(unaff_EBP + -0x2c) - *(float *)(iVar4 + 0x18c);
            FUN_00462be8(unaff_EBP + -0x34);
            FUN_004b9843();
            iStack_48 = *(undefined4 *)(unaff_EBP + 0xc);
            iStack_4c = iVar6 - *(int *)(unaff_EBP + -0x40);
            iStack_50 = iVar9 - *(int *)(unaff_EBP + -0x44);
            uStack_54 = *(undefined4 *)(unaff_EBP + -0x40);
            uStack_58 = *(undefined4 *)(unaff_EBP + -0x44);
            FUN_004ac510(*(undefined4 *)(unaff_EBP + 8));
            piVar8 = *(int **)(unaff_EBP + -0x20);
          }
          iVar9 = *(int *)(unaff_EBP + -0x1c);
        }
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

