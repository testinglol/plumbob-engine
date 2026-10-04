
undefined4 __fastcall FUN_00606e6a(int param_1)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x120) == 0) {
    piVar2 = (int *)(**(code **)*DAT_006fe8bc)();
    (**(code **)(*piVar2 + 0x1c))(&local_10,&local_c,&local_8);
    uVar3 = FUN_005dfe3b(local_10,local_c,local_8);
    *(uint *)(param_1 + 0x120) = uVar3 & 0xffff;
    if (*(int *)(param_1 + 0x108) != 0) {
      *(uint *)(*(int *)(param_1 + 0x108) + 100) = uVar3 & 0xffff;
    }
  }
  cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(1);
  if (cVar1 != '\0') {
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x40))
              (*(undefined4 *)(param_1 + 0x120),param_1 + 0x1c,0);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(1);
  }
  return 1;
}

