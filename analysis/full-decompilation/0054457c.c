
void __fastcall FUN_0054457c(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  uVar2 = param_1[0x43];
  if ((-1 < (int)uVar2) && (piVar1 = param_1 + 0x36, uVar2 < (uint)(param_1[0x37] - *piVar1 >> 2)))
  {
    iVar3 = *(int *)(*piVar1 + uVar2 * 4);
    if (iVar3 != 0) {
      FUN_005db2f2(*piVar1 + uVar2 * 4);
      FUN_004e1ae3(*(undefined4 *)(iVar3 + 0x1b4));
      FUN_005da4c7(iVar3);
      param_1[0x43] = -1;
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
      if ((int *)param_1[0x39] != (int *)0x0) {
        iVar3 = *(int *)param_1[0x39];
        if ((uint)(param_1[0x37] - *piVar1 >> 2) < 7) {
          (**(code **)(iVar3 + 0x98))();
        }
        else {
          (**(code **)(iVar3 + 0x94))();
          (**(code **)(*(int *)param_1[0x39] + 0x1ac))(0);
          (**(code **)(*(int *)param_1[0x39] + 0x1b0))((param_1[0x37] - *piVar1 >> 2) + -6);
          (**(code **)(*(int *)param_1[0x39] + 0x1d4))(6);
        }
      }
      if (6 < (uint)(param_1[0x37] - *piVar1 >> 2)) {
        if ((param_1[0x37] - *piVar1 >> 2) - 6U <= (uint)param_1[0x40]) {
          param_1[0x40] = param_1[0x40] - 1;
        }
      }
      if ((uint)(param_1[0x37] - *piVar1 >> 2) < 7) {
        param_1[0x40] = 0;
      }
      FUN_00544228();
      (**(code **)(*param_1 + 0x168))();
    }
  }
  return;
}

