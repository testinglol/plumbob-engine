
void __thiscall FUN_005de4fd(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 unaff_retaddr;
  
  cVar1 = (**(code **)(*param_1 + 0x8c))(4);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*param_1 + 0x128))(unaff_retaddr,param_2);
    if (cVar1 == '\0') {
      (**(code **)(*param_1 + 0x90))(8,0);
    }
    else {
      (**(code **)(*param_1 + 0x90))(8,1);
      (**(code **)(*param_1 + 0x80))(unaff_retaddr,param_2);
      FUN_005d98fc(param_1);
    }
  }
  return;
}

