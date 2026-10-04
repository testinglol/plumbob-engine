
uint FUN_004e913c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  undefined4 uVar3;
  undefined **local_50 [3];
  undefined1 local_44 [64];
  
  if ((((param_1 != 0) && (in_EAX = (int *)FUN_005a5e72(), (char)in_EAX != '\0')) &&
      (in_EAX = (int *)FUN_004e8a7a(), in_EAX != (int *)0x0)) &&
     ((piVar1 = (int *)*in_EAX, piVar1 != (int *)0x0 &&
      (in_EAX = (int *)(**(code **)(*piVar1 + 0x20))(), (char)in_EAX != '\0')))) {
    iVar2 = (**(code **)(*piVar1 + 0x38))(0x424d505f,param_2,0);
    if (iVar2 != 0) {
      (**(code **)(*piVar1 + 0x80))(iVar2);
    }
    uVar3 = FUN_004096c2(0,0,0);
    uVar3 = FUN_004b7ecc(uVar3);
    FUN_0046f824(local_44,0,0x40);
    local_50[0] = &PTR_FUN_0066651c;
    FUN_0046f847(param_3,0xffffffff);
    (**(code **)(*piVar1 + 0x74))(uVar3,0x424d505f,param_2,local_50,1);
    FUN_00465a06(uVar3);
    iVar2 = FUN_00401f6f();
    return (uint)(iVar2 == 0);
  }
  return (uint)in_EAX & 0xffffff00;
}

