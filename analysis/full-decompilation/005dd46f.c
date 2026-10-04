
undefined1 __thiscall FUN_005dd46f(int *param_1,char param_2,char param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined1 uVar10;
  int *local_c;
  int *piStack_8;
  
  uVar10 = 0;
  local_c = param_1;
  piStack_8 = param_1;
  if (param_2 == '\0') {
    if ((int *)param_1[0x16] != (int *)0x0) {
      cVar5 = (**(code **)(*(int *)param_1[0x16] + 0x2c))();
      if (cVar5 != '\0') {
        (**(code **)(*(int *)param_1[0x16] + 0x10))();
      }
      if ((undefined4 *)param_1[0x16] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)param_1[0x16])(1);
      }
      param_1[0x16] = 0;
    }
  }
  else {
    if (param_1[0x16] == 0) {
      piVar6 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
      iVar7 = (**(code **)(*piVar6 + 4))();
      param_1[0x16] = iVar7;
    }
    if ((int *)param_1[0x16] == (int *)0x0) goto LAB_005dd5c4;
    cVar5 = (**(code **)(*(int *)param_1[0x16] + 0x2c))();
    if (cVar5 != '\0') {
      piVar6 = (int *)param_1[0x16];
      if ((param_1[0x21] - param_1[0x1f] == piVar6[7]) &&
         (param_1[0x22] - param_1[0x20] == piVar6[8])) {
        return 1;
      }
      (**(code **)(*piVar6 + 0x10))();
    }
    if ((param_1[0x21] == param_1[0x1f]) || (param_1[0x22] == param_1[0x20])) goto LAB_005dd5c4;
    piVar6 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    iVar7 = param_1[0x21];
    iVar1 = param_1[0x1f];
    iVar2 = param_1[0x22];
    iVar3 = param_1[0x20];
    iVar4 = *(int *)param_1[0x16];
    puVar8 = (undefined4 *)(**(code **)(*piVar6 + 0xc))(&local_c,0,-(param_3 != '\0') & 2,0);
    cVar5 = (**(code **)(iVar4 + 0xc))(iVar7 - iVar1,iVar2 - iVar3,*puVar8,puVar8[1]);
    if (cVar5 == '\0') {
      uVar10 = 0;
      if ((undefined4 *)param_1[0x16] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)param_1[0x16])(1);
      }
      param_1[0x16] = 0;
      goto LAB_005dd5c4;
    }
    cVar5 = (**(code **)(*param_1 + 0x8c))(0x100);
    if (cVar5 != '\0') {
      piVar6 = (int *)FUN_005e7743();
      iVar7 = *(int *)param_1[0x16];
      uVar9 = (**(code **)(*piVar6 + 0x44))(0);
      (**(code **)(iVar7 + 0x68))(uVar9);
    }
  }
  uVar10 = 1;
LAB_005dd5c4:
  (**(code **)(*param_1 + 400))();
  (**(code **)(*param_1 + 0x168))();
  return uVar10;
}

