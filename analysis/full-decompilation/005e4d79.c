
undefined4 __thiscall FUN_005e4d79(int *param_1,char param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if ((char)param_1[0x39] != '\0') {
    if (param_1[0x38] == 0) {
      iVar8 = (**(code **)(*param_1 + 0xc4))();
      param_1[0x38] = iVar8;
    }
    if ((param_2 == '\0') && (param_1[0x38] != 0)) {
      cVar7 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
      if (cVar7 != '\0') {
        iVar8 = param_1[0x38];
        local_28 = *(undefined4 *)(iVar8 + 0x14);
        local_24 = *(undefined4 *)(iVar8 + 0x18);
        local_20 = *(undefined4 *)(iVar8 + 0x1c);
        local_1c = *(undefined4 *)(iVar8 + 0x20);
        local_18 = local_28;
        local_14 = local_24;
        local_10 = local_20;
        local_c = local_1c;
        FUN_004ba5ac(param_1 + 7);
        (**(code **)(*(int *)param_1[0x17] + 0x9c))(param_1[0x38],&local_28,&local_18,0);
        (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
      }
      puVar1 = (undefined4 *)param_1[0x38];
      if ((puVar1[7] - puVar1[5] != param_1[0x21] - param_1[0x1f]) ||
         (puVar1[8] - puVar1[6] != param_1[0x22] - param_1[0x20])) {
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        param_1[0x38] = 0;
        piVar9 = (int *)(**(code **)(*param_1 + 0x18))();
        (**(code **)(*piVar9 + 0x168))();
      }
    }
  }
  if (param_1[0x14] != param_1[0x13]) {
    iVar10 = (**(code **)(*(int *)param_1[0x36] + 0x58))();
    iVar8 = param_1[0x22];
    iVar2 = param_1[0x20];
    iVar3 = param_1[8];
    local_8 = *(int *)param_1[0x36];
    iVar4 = *(int *)(param_1[0x35] + 0x84);
    iVar5 = param_1[7];
    iVar6 = *(int *)(param_1[0x35] + 0x7c);
    uVar11 = FUN_004096c2(param_1[0x14] - param_1[0x13],0,0,0);
    (**(code **)(local_8 + 0x78))
              (param_1[0x17],((iVar4 + iVar5) - iVar6) + 6,((iVar8 - iVar2) - iVar10) / 2 + iVar3,
               uVar11);
  }
  return 1;
}

