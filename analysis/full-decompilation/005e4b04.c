
void __thiscall FUN_005e4b04(int param_1,int param_2)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  if ((*(char *)(param_1 + 0x172) != '\0') && (param_2 == 1)) {
    if (*(int *)(param_1 + 400) != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 400) = 1;
  }
  if (*(char *)(param_1 + 0x16f) == '\0') {
    if (*(int *)(param_1 + 0x48) != 0) {
      FUN_005da644(*(int *)(param_1 + 0x48),3,param_2,param_1,0);
    }
  }
  else {
    puVar1 = *(undefined4 **)(param_1 + 0x48);
    if ((puVar1 != (undefined4 *)0x0) && (cVar2 = FUN_005da398(puVar1), cVar2 != '\0')) {
      local_10 = param_2;
      local_14 = 3;
      local_8 = 0;
      local_c = param_1;
      (**(code **)*puVar1)(&local_14);
    }
  }
  return;
}

