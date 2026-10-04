
undefined1 FUN_005f8caf(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005728f7(extraout_ECX + 0x41b);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = FUN_00572a0a();
  FUN_005b86bd(uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d4d37();
  cVar2 = FUN_004317d5(unaff_EBP + -0x24,&DAT_006fecb8);
  if (cVar2 == '\0') {
    (**(code **)(*extraout_ECX + 0x4c))(0);
LAB_005f8d0e:
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
  }
  else {
    if ((char)extraout_ECX[0x41a] == '\0') {
      iVar1 = extraout_ECX[0xe];
      *(undefined1 *)(extraout_ECX + 0x41a) = 1;
      if (iVar1 != 0) {
        FUN_0062bc70();
        FUN_00634ecc(iVar1);
        extraout_ECX[0xe] = 0;
      }
      pvVar4 = _malloc(0x4a60);
      *(void **)(unaff_EBP + -0x14) = pvVar4;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      if (pvVar4 == (void *)0x0) {
        pvVar4 = (void *)0x0;
      }
      else {
        FUN_0062bca1();
        *(undefined4 *)((int)pvVar4 + 0x4a48) = 0;
        *(undefined4 *)((int)pvVar4 + 0x4a50) = 0;
        *(undefined1 *)((int)pvVar4 + 0x4a5c) = 1;
      }
      extraout_ECX[0xe] = (int)pvVar4;
      *(undefined4 *)((int)pvVar4 + 0x4a48) = 0;
      *(undefined4 *)((int)pvVar4 + 0x4a50) = 0;
      *(undefined1 *)((int)pvVar4 + 0x4a5c) = 1;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      extraout_ECX[0x416] = 0;
      extraout_ECX[0x415] = 0;
      pvVar4 = _malloc(0x2000);
      extraout_ECX[0xf] = (int)pvVar4;
      pvVar4 = _malloc(0x2000);
      extraout_ECX[0x10] = (int)pvVar4;
      (**(code **)(extraout_ECX[7] + 100))(extraout_ECX + 0x41b);
      cVar2 = (**(code **)extraout_ECX[7])(1,2,1);
      if (cVar2 == '\0') goto LAB_005f8d0e;
      (**(code **)(*extraout_ECX + 0x14))();
      if (*(char *)((int)extraout_ECX + 0x1079) == '\0') {
        iVar1 = *extraout_ECX;
        iVar5 = (**(code **)(iVar1 + 0x10))(unaff_EBP + -0x18,4);
        (**(code **)(iVar1 + 0x4c))(iVar5 != 0);
        (**(code **)(*extraout_ECX + 0x14))();
      }
    }
    *(undefined1 *)(unaff_EBP + -0xd) = 1;
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00572aec();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + -0xd);
}

