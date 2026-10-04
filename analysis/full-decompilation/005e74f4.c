
bool __thiscall FUN_005e74f4(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  bool bVar2;
  undefined1 local_14 [8];
  undefined4 local_c;
  int local_8;
  
  iVar1 = *(int *)(param_1 + 4);
  FUN_005e76d4(&local_8,&param_3);
  bVar2 = local_8 == iVar1;
  if (bVar2) {
    local_c = param_3;
    local_8 = param_2;
    FUN_00602b14(local_14,&local_c);
  }
  return bVar2;
}

