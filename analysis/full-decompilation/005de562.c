
void __thiscall FUN_005de562(int *param_1,int param_2)

{
  char cVar1;
  int unaff_retaddr;
  
  cVar1 = (**(code **)(*param_1 + 0x8c))(8);
  if (cVar1 != '\0') {
    FUN_00512c83(unaff_retaddr - param_1[0xc],param_2 - param_1[0xd]);
    if ((int *)param_1[0x10] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x10] + 0x168))();
    }
  }
  return;
}

