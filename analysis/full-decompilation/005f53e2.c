
void __thiscall FUN_005f53e2(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if ((-1 < param_2) && (piVar1 = param_1 + 0x35, param_2 < param_1[0x36] - *piVar1 >> 2)) {
    if (param_1[0x3e] == param_2) {
      param_1[0x3e] = -1;
      local_c = 0xffffffff;
      local_14 = 3;
      local_10 = 0x15;
      puVar5 = (undefined4 *)(**(code **)(*param_1 + 0x18))();
      if (puVar5 != (undefined4 *)0x0) {
        cVar4 = FUN_005da398(puVar5);
        if (cVar4 != '\0') {
          (**(code **)*puVar5)(&local_14);
        }
      }
    }
    piVar2 = (int *)(*piVar1 + param_2 * 4);
    iVar3 = *piVar2;
    if (iVar3 != 0) {
      FUN_005db2f2(piVar2);
      FUN_005da4c7(iVar3);
      if ((int *)param_1[0x38] != (int *)0x0) {
        iVar3 = *(int *)param_1[0x38];
        if (param_1[0x3a] < param_1[0x36] - *piVar1 >> 2) {
          (**(code **)(iVar3 + 0x94))();
          (**(code **)(*(int *)param_1[0x38] + 0x1ac))(0);
          (**(code **)(*(int *)param_1[0x38] + 0x1b0))
                    ((param_1[0x36] - *piVar1 >> 2) - param_1[0x3a]);
          (**(code **)(*(int *)param_1[0x38] + 0x1d4))(param_1[0x3a]);
        }
        else {
          (**(code **)(iVar3 + 0x98))();
        }
      }
      iVar3 = param_1[0x3a];
      if (iVar3 < param_1[0x36] - *piVar1 >> 2) {
        if ((param_1[0x36] - *piVar1 >> 2) - iVar3 <= param_1[0x3b]) {
          param_1[0x3b] = param_1[0x3b] + -1;
        }
      }
      if (param_1[0x36] - *piVar1 >> 2 <= iVar3) {
        param_1[0x3b] = 0;
      }
      FUN_005f50ff();
      (**(code **)(*param_1 + 0x168))();
    }
  }
  return;
}

