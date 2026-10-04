
void __thiscall FUN_00609c54(int *param_1,char *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  char *local_8;
  
  uVar2 = 0;
  local_8 = param_2;
  if (param_3 != 0) {
    while ((iVar1 = FUN_00609af3(local_8), iVar1 != 0 && (iVar1 + uVar2 <= param_3))) {
      if (iVar1 == 1) {
        (**(code **)(*param_1 + 0x38))((int)*local_8);
      }
      local_8 = local_8 + iVar1;
      uVar2 = iVar1 + uVar2;
    }
  }
  (**(code **)(*param_1 + 0x68))(param_2,uVar2);
  return;
}

