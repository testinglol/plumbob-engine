
void __thiscall FUN_005bd7b3(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[1];
  iVar2 = *param_1;
  if (param_2 < (uint)(iVar1 - iVar2)) {
    FUN_0047449a(iVar2 + param_2,iVar1);
  }
  else {
    FUN_005bdaad(iVar1,(iVar2 - iVar1) + param_2,param_3);
  }
  return;
}

