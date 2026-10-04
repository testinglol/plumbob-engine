
undefined4 __thiscall
FUN_005df33f(int *param_1,undefined4 param_2,int *param_3,int *param_4,char param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_24 = param_3[1];
  local_1c = param_3[3];
  local_20 = param_3[2];
  local_28 = *param_3;
  local_8 = local_1c - local_24;
  iVar2 = local_20 - local_28;
  local_18 = local_28;
  local_14 = local_24;
  local_10 = local_20;
  local_c = local_1c;
  FUN_005df565(*param_4,param_4[1]);
  (**(code **)(*param_1 + 0x9c))(param_2,&local_28,&local_18,0);
  local_28 = local_28 + iVar2;
  local_20 = local_20 + iVar2;
  local_18 = *param_4 + iVar2;
  local_10 = param_4[2] - iVar2;
  if (local_18 < local_10) {
    (**(code **)(*param_1 + 0xbc))(param_2,&local_28,&local_18,0,0);
  }
  local_28 = local_28 + iVar2;
  local_20 = local_20 + iVar2;
  local_18 = local_10;
  local_10 = param_4[2];
  (**(code **)(*param_1 + 0x9c))(param_2,&local_28,&local_18,0);
  FUN_005df565(*param_3,param_3[1] + local_8);
  local_18 = *param_4;
  local_10 = iVar2 + local_18;
  iVar3 = param_4[3] - local_8;
  local_14 = local_c;
  bVar1 = local_c < iVar3;
  local_c = iVar3;
  if (bVar1) {
    (**(code **)(*param_1 + 0xbc))(param_2,&local_28,&local_18,0,0);
  }
  local_28 = local_28 + iVar2;
  local_20 = local_20 + iVar2;
  local_18 = local_10;
  iVar3 = param_4[2] - iVar2;
  if (((param_5 != '\0') && (local_10 < iVar3)) && (local_14 < local_c)) {
    local_10 = iVar3;
    (**(code **)(*param_1 + 0xbc))(param_2,&local_28,&local_18,0,0);
    iVar3 = local_10;
  }
  local_28 = local_28 + iVar2;
  local_20 = local_20 + iVar2;
  local_10 = param_4[2];
  local_18 = iVar3;
  if (local_14 < local_c) {
    (**(code **)(*param_1 + 0xbc))(param_2,&local_28,&local_18,0,0);
  }
  FUN_005df565(*param_3,local_1c);
  local_18 = *param_4;
  local_10 = local_18 + iVar2;
  local_14 = local_c;
  local_c = local_c + local_8;
  (**(code **)(*param_1 + 0x9c))(param_2,&local_28,&local_18,0);
  local_28 = local_28 + iVar2;
  local_20 = local_20 + iVar2;
  iVar3 = param_4[2] - iVar2;
  local_18 = local_10;
  bVar1 = local_10 < iVar3;
  local_10 = iVar3;
  if (bVar1) {
    (**(code **)(*param_1 + 0xbc))(param_2,&local_28,&local_18,0,0);
  }
  local_28 = local_28 + iVar2;
  local_20 = local_20 + iVar2;
  local_18 = local_10;
  local_10 = param_4[2];
  (**(code **)(*param_1 + 0x9c))(param_2,&local_28,&local_18,0);
  return 1;
}

