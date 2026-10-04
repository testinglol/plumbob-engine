
void FUN_004fb1a5(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(char *)(extraout_ECX + 0xf5) == '\0') goto LAB_004fb48c;
  uVar2 = (**(code **)(*DAT_006fe8bc + 0x34))();
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_004f77dc();
  pvVar3 = operator_new(0x1b8);
  *(void **)(unaff_EBP + -0x48) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_005f179a();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (piVar4 != (int *)0x0) {
    FUN_005f42c3(DAT_006f2a9c);
    FUN_005f4336(DAT_006f2a48);
    FUN_005f4256(DAT_006f2a50,DAT_006f2a48,DAT_006f2a48);
    (**(code **)(*piVar4 + 0x60))(0x14,0x14,0xdc,0x29);
    piVar4[2] = (int)piVar4;
    FUN_005f435f(0xff);
    FUN_005f42b6(1);
    FUN_005f4294(0);
    FUN_005f42a1(0);
    (**(code **)(*piVar4 + 0x90))(0x10000,1);
    FUN_005f4352(1);
    piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    piVar5 = (int *)(**(code **)(*piVar5 + 8))();
    (**(code **)(*piVar5 + 0x1bc))(piVar4);
  }
  FUN_004ff6fa(0x7072666e,s_Setting_up_personfinder_006cbfa4);
  FUN_004e8b14();
  FUN_004ff6fa(0x66617070,s_Finished_app_init_006cbf90);
  iVar6 = *(int *)(extraout_ECX + 0x110);
  if (iVar6 != 0) {
    (**(code **)(*DAT_006fe8bc + 0x18))(iVar6);
    FUN_005da4c7(iVar6);
    *(undefined4 *)(extraout_ECX + 0x110) = 0;
  }
  if (*(undefined4 **)(extraout_ECX + 0x114) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(extraout_ECX + 0x114))(1);
  }
  *(undefined4 *)(extraout_ECX + 0x114) = 0;
  if ((DAT_006e486c != 0) && (*(int *)(DAT_006e486c + 0x2c) != 0)) {
    *(undefined4 *)(*(int *)(DAT_006e486c + 0x2c) + 0x60) = 0;
  }
  (**(code **)(**(int **)(extraout_ECX + 0x80) + 0x94))();
  *(undefined4 *)(unaff_EBP + -0x10) = 0xffffffff;
  FUN_0046f824(unaff_EBP + -0x14c,0,0x104);
  *(undefined ***)(unaff_EBP + -0x158) = &PTR_FUN_006664e8;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 1;
  cVar1 = FUN_005d6516(s_house_006cb814,unaff_EBP + -0x2c,1);
  if (cVar1 != '\0') {
    FUN_00634d24(*(undefined4 *)(unaff_EBP + -0x2c),&DAT_006c08e4,unaff_EBP + -0x10);
  }
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  cVar1 = FUN_005d6516(&DAT_006cbf88,unaff_EBP + -0x44,1);
  if (cVar1 != '\0') {
    FUN_0046f8cb(*(undefined4 *)(unaff_EBP + -0x44));
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  if (*(int *)(unaff_EBP + -0x10) == -1) {
    iVar6 = FUN_00428886();
    if (iVar6 != 0) goto LAB_004fb3ff;
    FUN_004f5aa0(0);
  }
  else {
    FUN_004f1b96(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
LAB_004fb3ff:
    (**(code **)(**(int **)(extraout_ECX + 0x84) + 0x94))();
  }
  FUN_00436e16();
  FUN_004fae43();
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 3;
  cVar1 = FUN_005d6516(&DAT_006cb640,unaff_EBP + -0x20,1);
  if (cVar1 != '\0') {
    FUN_005d4956(&DAT_006cbf80);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + -0x1c));
    FUN_005e64a0(*(undefined4 *)(unaff_EBP + -0x38));
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_004fb48c:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

