
undefined1 __fastcall FUN_005ec83d(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined1 local_5;
  
  *(undefined1 *)(param_1 + 1) = 0;
  piVar1 = param_1 + 0x27;
  if (param_1[0x28] - param_1[0x27] >> 3 != 0) {
    if (1 < (uint)(param_1[0x28] - *piVar1 >> 3)) {
      iVar5 = param_1[0x28] - *piVar1 >> 3;
      while( true ) {
        iVar5 = iVar5 + -1;
        if (iVar5 < 2) break;
        iVar6 = iVar5 * 8;
        iVar2 = *(int *)(iVar6 + 4 + *piVar1);
        if (iVar2 != 0) {
          (**(code **)(**(int **)(*piVar1 + 0xc) + 0x28))(iVar2);
          (**(code **)(**(int **)(*piVar1 + 4 + iVar6) + 4))();
          puVar3 = *(undefined4 **)(*piVar1 + 4 + iVar6);
          if (puVar3 != (undefined4 *)0x0) {
            (**(code **)*puVar3)(1);
          }
          *(undefined4 *)(*piVar1 + 4 + iVar6) = 0;
        }
      }
    }
    FUN_004a1827(*piVar1,param_1[0x28]);
  }
  local_5 = (**(code **)(*param_1 + 0xe4))();
  if ((int *)param_1[0x26] != (int *)0x0) {
    cVar4 = (**(code **)(*(int *)param_1[0x26] + 4))();
    if (cVar4 == '\0') {
      local_5 = 0;
    }
    if ((undefined4 *)param_1[0x26] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x26])(1);
    }
    param_1[0x26] = 0;
  }
  if ((undefined4 *)param_1[0x2a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x2a])(1);
  }
  param_1[0x2a] = 0;
  if (param_1[0x17] != 0) {
    FUN_005e3581();
    param_1[0x17] = 0;
  }
  if (param_1[0x18] != 0) {
    FUN_005e3581();
    param_1[0x18] = 0;
  }
  return local_5;
}

