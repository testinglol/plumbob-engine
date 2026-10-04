
undefined1 FUN_005120af(void)

{
  char cVar1;
  undefined1 uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    cVar1 = FUN_005dbf32();
    uVar2 = 0;
    if (cVar1 != '\0') {
      (**(code **)(*extraout_ECX + 0x174))(1,0);
      FUN_005ddfdc(1);
      (**(code **)(*extraout_ECX + 0x90))(4,1);
      FUN_004e609e();
      cVar1 = FUN_004e6133();
      if (cVar1 != '\0') {
        (**(code **)(*extraout_ECX + 0x58))(1,0x80);
      }
      extraout_ECX[0x36] = DAT_006f2a90;
      FUN_004cb1a2(200,200);
      extraout_ECX[0x4a] = DAT_006f2a54;
      extraout_ECX[0x4b] = DAT_006f2a5c;
      extraout_ECX[0x4c] = DAT_006f2a68;
      extraout_ECX[0x4d] = 0xffff;
      extraout_ECX[0x4e] = DAT_006f2a60;
      extraout_ECX[0x4f] = DAT_006f2a44;
      extraout_ECX[0x35] = 0x47cccccd;
      pvVar3 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar3 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x37] = iVar4;
      if (iVar4 != 0) {
        FUN_005a5631(0x1e,unaff_EBP + -0x10,4);
        if (*(int **)(unaff_EBP + -0x10) != (int *)0x0) {
          (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x68))(DAT_006f2a64);
          (**(code **)(*(int *)extraout_ECX[0x37] + 0x19c))(*(undefined4 *)(unaff_EBP + -0x10),4,1);
          *(undefined1 *)(extraout_ECX[0x37] + 0x16b) = 1;
          (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x37]);
        }
      }
      (**(code **)(*extraout_ECX + 0x60))
                (extraout_ECX[0x1f],extraout_ECX[0x20],extraout_ECX[0x21],extraout_ECX[0x22]);
      (**(code **)(*extraout_ECX + 0x90))(0x10000,1);
      uVar5 = FUN_005e749a(0);
      FUN_005dde6d(uVar5);
      (**(code **)(*extraout_ECX + 0x94))();
      uVar2 = 1;
    }
  }
  else {
    uVar2 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

