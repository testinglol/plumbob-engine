
void FUN_0050a876(int *param_1,undefined4 param_2)

{
  char cVar1;
  
  if (param_1 != (int *)0x0) {
    FUN_004e609e();
    cVar1 = FUN_004e6133();
    if (cVar1 == '\0') {
      if ((char)param_2 == '\0') {
        (**(code **)(*param_1 + 0x98))();
      }
      else {
        (**(code **)(*param_1 + 0x94))();
      }
    }
    else {
      (**(code **)(*param_1 + 0xa8))(param_2,0,0);
    }
  }
  return;
}

