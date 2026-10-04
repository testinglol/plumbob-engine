
void __thiscall FUN_0046b837(int *param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  undefined **local_228 [3];
  undefined1 local_21c [260];
  undefined **local_118 [3];
  undefined1 local_10c [260];
  int *local_8;
  
  local_8 = param_1;
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 != '\0') {
    FUN_0046f824(local_10c,0,0x104);
    local_118[0] = &PTR_FUN_006664e8;
    FUN_0046f824(local_21c,0,0x104);
    local_228[0] = &PTR_FUN_006664e8;
    piVar2 = (int *)FUN_004066e7(0);
    (**(code **)(*piVar2 + 0x24))(local_118);
    FUN_00412209(local_118,param_2,local_228);
  }
  return;
}

