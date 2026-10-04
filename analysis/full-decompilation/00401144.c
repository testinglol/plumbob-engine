
void __fastcall FUN_00401144(undefined4 *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)*param_1)();
  if (cVar1 == '\r') {
    param_1[2] = param_1[2] + 2;
    param_1[1] = param_1[1] | 3;
  }
  return;
}

