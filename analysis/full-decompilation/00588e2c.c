
undefined4 FUN_00588e2c(int param_1,char *param_2,char *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *_Str1;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_c;
  int local_8;
  
  local_c = 0;
  iVar7 = *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2;
  if (0 < iVar7) {
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0x20) + local_c * 4);
      iVar3 = *(int *)(iVar2 + 0x30);
      if (iVar3 != 0) {
        iVar8 = *(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 3;
        while (iVar8 = iVar8 + -1, -1 < iVar8) {
          local_8 = 0;
          uVar4 = *(undefined4 *)(*(int *)(iVar3 + 4) + iVar8 * 8);
          iVar5 = *(int *)(*(int *)(iVar3 + 4) + 4 + iVar8 * 8);
          iVar9 = *(int *)(iVar5 + 8) - *(int *)(iVar5 + 4) >> 3;
          if (0 < iVar9) {
            do {
              puVar1 = (undefined4 *)(*(int *)(iVar5 + 4) + local_8 * 8);
              _Str1 = (char *)puVar1[1];
              iVar6 = _strcmp((char *)*puVar1,param_2);
              if ((iVar6 == 0) && (iVar6 = _strcmp(_Str1,param_3), iVar6 == 0)) {
                FUN_005d499c(iVar2);
                return uVar4;
              }
              local_8 = local_8 + 1;
            } while (local_8 < iVar9);
          }
        }
      }
      local_c = local_c + 1;
    } while (local_c < iVar7);
  }
  FUN_005d4bbf(&DAT_006de560);
  return 0xffffffff;
}

