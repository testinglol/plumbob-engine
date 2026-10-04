
void __thiscall FUN_005442f7(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  if (param_2 != 0) {
    if (-1 < param_1[0x43]) {
      FUN_005e46f0(0);
    }
    (**(code **)(*param_1 + 0x20))(param_2);
    piVar1 = param_1 + 0x36;
    FUN_005449b6(*piVar1,&param_2);
    param_1[0x43] = 0;
    param_1[0x40] = 0;
    FUN_005e46f0(1);
    if ((int *)param_1[0x39] != (int *)0x0) {
      iVar2 = *(int *)param_1[0x39];
      if ((uint)(param_1[0x37] - *piVar1 >> 2) < 7) {
        (**(code **)(iVar2 + 0x98))();
      }
      else {
        (**(code **)(iVar2 + 0x94))();
        (**(code **)(*(int *)param_1[0x39] + 0x1ac))(0);
        (**(code **)(*(int *)param_1[0x39] + 0x1b0))((param_1[0x37] - *piVar1 >> 2) + -6);
        (**(code **)(*(int *)param_1[0x39] + 0x1a8))(param_1[0x40]);
        (**(code **)(*(int *)param_1[0x39] + 0x1d4))(6);
      }
    }
    FUN_00544228();
    (**(code **)(*param_1 + 0x168))();
    local_c = param_1[0x43];
    local_14 = 3;
    local_10 = 0x15;
    puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x18))();
    if (puVar4 != (undefined4 *)0x0) {
      cVar3 = FUN_005da398(puVar4);
      if (cVar3 != '\0') {
        (**(code **)*puVar4)(&local_14);
      }
    }
  }
  return;
}

