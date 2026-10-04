
int * FUN_005e7ac5(void)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  void *pvVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar7;
  
  FUN_00634c24();
  pvVar4 = operator_new(0xe8);
  *(void **)(unaff_EBP + -0x14) = pvVar4;
  piVar7 = (int *)0x0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar4 != (void *)0x0) {
    piVar7 = (int *)FUN_005e4ba8();
  }
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  puVar5 = (undefined4 *)(**(code **)(iVar1 + 0x10))(1);
  *(undefined4 **)(unaff_EBP + -0x10) = puVar5;
  if ((piVar7 != (int *)0x0) && (puVar5 != (undefined4 *)0x0)) {
    cVar2 = (**(code **)(*extraout_ECX + 0x18))(1);
    if (cVar2 != '\0') {
      *(undefined4 *)(unaff_EBP + -0x14) = *puVar5;
      uVar3 = FUN_005dfe3b(0xff,0,0xff);
      (**(code **)(*(int *)(unaff_EBP + -0x14) + 0x68))(uVar3);
    }
    uVar6 = *(undefined4 *)(unaff_EBP + 0xc);
    piVar7[2] = *(int *)(unaff_EBP + 8);
    (**(code **)(*piVar7 + 0x9c))(uVar6);
    uVar6 = (**(code **)(*extraout_ECX + 8))(0);
    FUN_005e4f56(uVar6);
    FUN_005e4f47(puVar5);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar7;
}

