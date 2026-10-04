
uint __fastcall FUN_005f953f(uint param_1)

{
  int *piVar1;
  int iVar2;
  uint local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x80);
  if (piVar1 != (int *)0x0) {
    local_c = param_1;
    local_8 = param_1;
    iVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,&local_8,&local_c);
    return ~-(uint)(iVar2 != 0) & local_8;
  }
  return 0;
}

