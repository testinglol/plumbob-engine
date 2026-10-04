
uint FUN_005dc436(int *param_1)

{
  char cVar1;
  char cVar2;
  uint in_EAX;
  uint uVar3;
  
  if (param_1 == (int *)0x0) {
    uVar3 = in_EAX & 0xffffff00;
  }
  else {
    cVar1 = FUN_005dc364(param_1);
    cVar2 = (**(code **)(*param_1 + 0x10))();
    FUN_005da4c7(param_1);
    uVar3 = (uint)(cVar2 != '\0' && cVar1 != '\0');
  }
  return uVar3;
}

