
void __thiscall
FUN_0048ccf3(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  char cVar2;
  
  iVar1 = param_1[0x1a];
  if ((((iVar1 != 0x1d) && (iVar1 != 0x2a)) && (iVar1 != 0x1e)) &&
     (cVar2 = FUN_00484ba0(&param_2), cVar2 != '\0')) {
    return;
  }
  (**(code **)(*param_1 + 0x78))(param_2,param_3,param_4,param_5);
  return;
}

