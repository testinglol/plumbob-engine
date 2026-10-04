
undefined4 FUN_00451af7(void)

{
  undefined2 *puVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  undefined4 uVar3;
  char *_Str;
  size_t sVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar5;
  
  FUN_00634c24();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x78) = &PTR_FUN_0066643c;
  puVar1 = *(undefined2 **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar5 = 0;
  uVar2 = CONCAT22(extraout_var,*puVar1);
  uVar3 = FUN_00401f6f(uVar2,0);
  FUN_00470383(uVar3,uVar2,uVar5);
  _Str = (char *)FUN_004705f2((int)(short)puVar1[1],0xffffffff);
  if (_Str != (char *)0x0) {
    sVar4 = _strlen(_Str);
    if (sVar4 != 0) {
      FUN_00635858(unaff_EBP + -0x178,s__s____s_006c4120,
                   *(undefined4 *)(*(int *)(extraout_ECX + 0x11c) + 0x18),_Str);
      FUN_0040766a(0xeb,unaff_EBP + -0x178);
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

