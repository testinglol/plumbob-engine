
uint FUN_004acf34(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int unaff_EBP;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  FUN_00634c24();
  FUN_0046f824(unaff_EBP + -0x178,0,0x104);
  *(undefined ***)(unaff_EBP + -0x184) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x288,0,0x104);
  *(undefined ***)(unaff_EBP + -0x294) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x398,0,0x104);
  uVar6 = 0xffffffff;
  *(undefined ***)(unaff_EBP + -0x3a4) = &PTR_FUN_006664e8;
  uVar3 = FUN_0041532c(8,0xffffffff);
  FUN_0046f847(uVar3,uVar6);
  FUN_0046f847(s_ambient_txt_006c73a0,0xffffffff);
  FUN_004ee9ce(*(undefined4 *)(unaff_EBP + -0x180),*(undefined4 *)(unaff_EBP + -0x290),
               unaff_EBP + -0x3a4);
  FUN_0063344c(1);
  uVar3 = DAT_00689070;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00633510(*(undefined4 *)(unaff_EBP + -0x3a0),0x21,uVar3);
  if (*(int *)(unaff_EBP + -0x6c + *(int *)(*(int *)(unaff_EBP + -0x74) + 4)) == 0) {
    iVar7 = unaff_EBP + -0x18;
    iVar5 = unaff_EBP + -0x10;
    FUN_00633585(unaff_EBP + -0x14);
    FUN_00633585(iVar5);
    FUN_00633585(iVar7);
    uVar4 = *(uint *)(unaff_EBP + -0x14);
    if (0xff < uVar4) {
      uVar4 = 0xff;
      *(undefined4 *)(unaff_EBP + -0x14) = 0xff;
    }
    if (0xff < *(uint *)(unaff_EBP + -0x10)) {
      *(undefined4 *)(unaff_EBP + -0x10) = 0xff;
    }
    if (0xff < *(uint *)(unaff_EBP + -0x18)) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0xff;
    }
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x18) = 0xb4;
    *(undefined4 *)(unaff_EBP + -0x10) = 0xb4;
    *(undefined4 *)(unaff_EBP + -0x14) = 0xb4;
    MessageBoxA((HWND)0x0,s_Could_not_open_TDSScen_Lights_am_006c7360,s_Development_Error_006c738c,0
               );
    uVar4 = *(uint *)(unaff_EBP + -0x14);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(uint *)(unaff_EBP + -0x10);
  uVar2 = *(uint *)(unaff_EBP + -0x18);
  FUN_006334fd();
  FUN_00632b08();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return ((uVar4 | 0xffffff00) << 8 | uVar1) << 8 | uVar2;
}

