
void __thiscall FUN_0043b981(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined **local_248 [3];
  undefined1 local_23c [260];
  undefined **local_138 [3];
  undefined1 local_12c [260];
  undefined **local_28 [3];
  undefined1 local_1c [8];
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  FUN_0046f824(local_23c,0,0x104);
  local_248[0] = &PTR_FUN_006664e8;
  FUN_0046f824(local_12c,0,0x104);
  local_138[0] = &PTR_FUN_006664e8;
  FUN_00412209(param_2,local_138,local_248);
  FUN_0046f9f6();
  FUN_0046f824(local_1c,0,8);
  local_28[0] = &PTR_FUN_00666644;
  FUN_0046f847(&DAT_006c2648,0xffffffff);
  iVar4 = FUN_0046f973(local_28);
  if (iVar4 == 0) {
    piVar5 = (int *)FUN_0043e530(local_138,*(undefined1 *)(param_1 + 0x1241));
    if (piVar5 != (int *)0x0) {
      cVar3 = (**(code **)(*piVar5 + 0x28))();
      if (cVar3 != '\0') {
        local_14 = (**(code **)(*piVar5 + 0x34))(0x4f424a44);
        local_8 = 1;
        if (0 < (short)local_14) {
          do {
            uVar6 = (**(code **)(*piVar5 + 0x40))(0x4f424a44,local_8,FUN_0042004f);
            (**(code **)(*piVar5 + 0x50))(uVar6,&local_10);
            FUN_00465a06(uVar6);
            bVar2 = false;
            uVar7 = 0;
            local_c = 0;
            if (*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2 == 0) {
LAB_0043baf2:
              uVar6 = local_10;
              uVar9 = param_3;
              uVar8 = FUN_0043e530(local_138,
                                   CONCAT31((int3)(uVar7 >> 8),*(undefined1 *)(param_1 + 0x1241)));
              FUN_0043bb37(uVar8,uVar6,uVar9);
            }
            else {
              do {
                piVar1 = *(int **)(*(int *)(param_1 + 0x20) + uVar7 * 4);
                if ((piVar5 == (int *)*piVar1) &&
                   ((short)local_10 == (short)((uint)piVar1[0x2d] >> 0x10))) {
                  bVar2 = true;
                }
                local_c = local_c + 1;
                uVar7 = (uint)(short)local_c;
              } while (uVar7 < (uint)(*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2));
              if (!bVar2) goto LAB_0043baf2;
            }
            local_8 = local_8 + 1;
          } while ((short)local_8 <= (short)local_14);
        }
      }
      FUN_0043e5bf(piVar5);
    }
  }
  return;
}

