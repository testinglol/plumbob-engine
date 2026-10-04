
void FUN_004efb69(void)

{
  undefined *puVar1;
  undefined2 uVar2;
  int *piVar3;
  int *piVar4;
  size_t sVar5;
  undefined4 uVar6;
  int iVar7;
  void *pvVar8;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar4 = DAT_006fe8bc;
  *(undefined4 *)(unaff_EBP + -0x24) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  iVar7 = *piVar4;
  *(int **)(unaff_EBP + -0x1c) = piVar4;
  (**(code **)(iVar7 + 0x10))();
  piVar3 = (int *)FUN_005e7743();
  piVar4 = (int *)(**(code **)(*piVar4 + 0x1c))();
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004f2baf(unaff_EBP + -0x3c);
  sVar5 = _strlen(&DAT_006cabe4);
  FUN_00412d8a(&DAT_006cabe4,&DAT_006cabe4 + sVar5);
  FUN_005b86bd(unaff_EBP + -0x3c);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  sVar5 = _strlen(s_UI_Shared_Sys__006cabd4);
  FUN_00412d8a(s_UI_Shared_Sys__006cabd4,s_UI_Shared_Sys__006cabd4 + sVar5);
  FUN_005b86bd(unaff_EBP + -0x3c);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  sVar5 = _strlen(s_Text__006cabcc);
  FUN_00412d8a(s_Text__006cabcc,s_Text__006cabcc + sVar5);
  FUN_005b86bd(unaff_EBP + -0x3c);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  sVar5 = _strlen(s_UI_Shared_DLG__006cabbc);
  FUN_00412d8a(s_UI_Shared_DLG__006cabbc,s_UI_Shared_DLG__006cabbc + sVar5);
  (**(code **)(*piVar4 + 0x38))(0xa6,0xb4,0xb4);
  piVar4 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0xff,0,0xff);
  (**(code **)(iVar7 + 0x48))(0,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0xbd,0xbc,0xbc);
  (**(code **)(iVar7 + 0x48))(1,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0xff,0xff,0xff);
  (**(code **)(iVar7 + 0x48))(2,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0,0,0);
  (**(code **)(iVar7 + 0x48))(4,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0x80,0,0);
  (**(code **)(iVar7 + 0x48))(5,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0,0x80,0);
  (**(code **)(iVar7 + 0x48))(6,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0x80,0x80,0x40);
  (**(code **)(iVar7 + 0x48))(7,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0,0,0x80);
  (**(code **)(iVar7 + 0x48))(8,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0x80,0,0x80);
  (**(code **)(iVar7 + 0x48))(9,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0,0x80,0x80);
  (**(code **)(iVar7 + 0x48))(10,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0x80,0x80,0x80);
  (**(code **)(iVar7 + 0x48))(0xb,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0xc0,0xc0,0xc0);
  (**(code **)(iVar7 + 0x48))(0xc,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0xff,0,0);
  (**(code **)(iVar7 + 0x48))(0xd,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0,0xff,0);
  (**(code **)(iVar7 + 0x48))(0xe,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0xff,0xff,0);
  (**(code **)(iVar7 + 0x48))(0xf,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0,0,0xff);
  (**(code **)(iVar7 + 0x48))(0x10,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0,0xff,0xff);
  (**(code **)(iVar7 + 0x48))(0x11,uVar2);
  iVar7 = *piVar3;
  uVar2 = (**(code **)(*piVar4 + 0x38))(0xff,0xff,0xff);
  (**(code **)(iVar7 + 0x48))(0x12,uVar2);
  piVar4 = (int *)FUN_005e7743();
  uVar6 = (**(code **)(*piVar4 + 0x44))(0);
  (**(code **)(*piVar3 + 0xc))(0,DAT_006f2aa0);
  (**(code **)(*piVar3 + 0xc))(1,DAT_006f2ad0);
  FUN_005a5631(0x12,unaff_EBP + -0x20,4);
  (**(code **)(*piVar3 + 0x14))(1,*(undefined4 *)(unaff_EBP + -0x20),1);
  FUN_005a5631(0x11,unaff_EBP + -0x20,4);
  (**(code **)(*piVar3 + 0x14))(0,*(undefined4 *)(unaff_EBP + -0x20),0);
  FUN_005a5631(0xbc0,unaff_EBP + -0x20,4);
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    (**(code **)(*piVar3 + 0x14))(5,*(undefined4 *)(unaff_EBP + -0x20),0);
  }
  FUN_005a5631(0x13,unaff_EBP + -0x20,4);
  (**(code **)(*piVar3 + 0x14))(2,*(undefined4 *)(unaff_EBP + -0x20),0);
  FUN_005a5631(0x14,unaff_EBP + -0x20,4);
  (**(code **)(*piVar3 + 0x14))(3,*(undefined4 *)(unaff_EBP + -0x20),0);
  FUN_005a5631(0x15,unaff_EBP + -0x20,4);
  if (*(int **)(unaff_EBP + -0x20) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x68))(DAT_006f2a64);
  }
  (**(code **)(*piVar3 + 0x14))(4,*(undefined4 *)(unaff_EBP + -0x20),0);
  FUN_005a5631(0x16,unaff_EBP + -0x20,4);
  (**(code **)(*piVar3 + 0x14))(9,*(undefined4 *)(unaff_EBP + -0x20),0);
  FUN_005a5631(0x18,unaff_EBP + -0x20,4);
  (**(code **)(*piVar3 + 0x14))(0xb,*(undefined4 *)(unaff_EBP + -0x20),0);
  FUN_005a5631(0x1a,unaff_EBP + -0x20,4);
  (**(code **)(*piVar3 + 0x14))(0xe,*(undefined4 *)(unaff_EBP + -0x20),0);
  FUN_005a5631(0x1b,unaff_EBP + -0x20,4);
  (**(code **)(*piVar3 + 0x14))(0xd,*(undefined4 *)(unaff_EBP + -0x20),0);
  FUN_005a5631(0x1c,unaff_EBP + -0x20,4);
  (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x68))(uVar6);
  (**(code **)(*piVar3 + 0x14))(0xf,*(undefined4 *)(unaff_EBP + -0x20),0);
  FUN_005a5631(0x1d,unaff_EBP + -0x20,4);
  (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x68))(uVar6);
  (**(code **)(*piVar3 + 0x14))(0x10,*(undefined4 *)(unaff_EBP + -0x20),0);
  iVar7 = (**(code **)(**(int **)(unaff_EBP + -0x1c) + 0x18))();
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar7 + 0x170);
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_004f2baf(unaff_EBP + -0x30);
  puVar1 = PTR_s_UIGraphics_shared_cursors__006c9f68;
  sVar5 = _strlen(PTR_s_UIGraphics_shared_cursors__006c9f68);
  FUN_00412d8a(puVar1,puVar1 + sVar5);
  FUN_005e753d(0,1);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,PTR_s_arrow_cur_006c9f6c);
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_005b86bd(uVar6);
    *(undefined4 *)(unaff_EBP + -0x10) = 3;
    *(undefined4 *)(unaff_EBP + -4) = 7;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 8;
  if ((*(byte *)(unaff_EBP + -0x10) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0);
  FUN_005e753d(3,1);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,PTR_s_hourglass_cur_006c9f70);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 4;
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 8;
    *(undefined4 *)(unaff_EBP + -4) = 0xc;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xd;
  if ((*(byte *)(unaff_EBP + -0x10) & 8) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffff7;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x10) & 4) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffb;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,3);
  FUN_005e753d(2,1);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,PTR_s_edit_cur_006c9f74);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 0x10;
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 0x20;
    *(undefined4 *)(unaff_EBP + -4) = 0x11;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x12;
  if ((*(byte *)(unaff_EBP + -0x10) & 0x20) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xffffffdf;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x10) & 0x10) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xffffffef;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,2);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x14;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,PTR_s_finger_cur_006c9f84);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 0x40;
    *(undefined1 *)(unaff_EBP + -4) = 0x15;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x10) = *(byte *)(unaff_EBP + -0x10) | 0x80;
    *(undefined4 *)(unaff_EBP + -4) = 0x16;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x17;
  if ((*(byte *)(unaff_EBP + -0x10) & 0x80) != 0) {
    *(byte *)(unaff_EBP + -0x10) = *(byte *)(unaff_EBP + -0x10) & 0x7f;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x10) & 0x40) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xffffffbf;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,4);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x19;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_SimsDelete_cur_006cabac);
    *(byte *)(unaff_EBP + -0xf) = *(byte *)(unaff_EBP + -0xf) | 1;
    *(undefined1 *)(unaff_EBP + -4) = 0x1a;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 0x200;
    *(undefined4 *)(unaff_EBP + -4) = 0x1b;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x1c;
  if ((*(uint *)(unaff_EBP + -0x10) & 0x200) != 0) {
    *(byte *)(unaff_EBP + -0xf) = *(byte *)(unaff_EBP + -0xf) & 0xfd;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0xf) & 1) != 0) {
    *(byte *)(unaff_EBP + -0xf) = *(byte *)(unaff_EBP + -0xf) & 0xfe;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,6);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x1e;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_SimsLevel_cur_006cab9c);
    *(byte *)(unaff_EBP + -0xf) = *(byte *)(unaff_EBP + -0xf) | 4;
    *(undefined1 *)(unaff_EBP + -4) = 0x1f;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 0x800;
    *(undefined4 *)(unaff_EBP + -4) = 0x20;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x21;
  if ((*(uint *)(unaff_EBP + -0x10) & 0x800) != 0) {
    *(byte *)(unaff_EBP + -0xf) = *(byte *)(unaff_EBP + -0xf) & 0xf7;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0xf) & 4) != 0) {
    *(byte *)(unaff_EBP + -0xf) = *(byte *)(unaff_EBP + -0xf) & 0xfb;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,7);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x23;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_SimsLower_cur_006cab8c);
    *(byte *)(unaff_EBP + -0xf) = *(byte *)(unaff_EBP + -0xf) | 0x10;
    *(undefined1 *)(unaff_EBP + -4) = 0x24;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 0x2000;
    *(undefined4 *)(unaff_EBP + -4) = 0x25;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x26;
  if ((*(uint *)(unaff_EBP + -0x10) & 0x2000) != 0) {
    *(byte *)(unaff_EBP + -0xf) = *(byte *)(unaff_EBP + -0xf) & 0xdf;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0xf) & 0x10) != 0) {
    *(byte *)(unaff_EBP + -0xf) = *(byte *)(unaff_EBP + -0xf) & 0xef;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,8);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x28;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_SimsMove_cur_006cab7c);
    *(byte *)(unaff_EBP + -0xf) = *(byte *)(unaff_EBP + -0xf) | 0x40;
    *(undefined1 *)(unaff_EBP + -4) = 0x29;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 0x8000;
    *(undefined4 *)(unaff_EBP + -4) = 0x2a;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x2b;
  if ((*(uint *)(unaff_EBP + -0x10) & 0x8000) != 0) {
    *(byte *)(unaff_EBP + -0xf) = *(byte *)(unaff_EBP + -0xf) & 0x7f;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0xf) & 0x40) != 0) {
    *(byte *)(unaff_EBP + -0xf) = *(byte *)(unaff_EBP + -0xf) & 0xbf;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,10);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x2d;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_SimsPlace_cur_006cab6c);
    *(byte *)(unaff_EBP + -0xe) = *(byte *)(unaff_EBP + -0xe) | 1;
    *(undefined1 *)(unaff_EBP + -4) = 0x2e;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 0x20000;
    *(undefined4 *)(unaff_EBP + -4) = 0x2f;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x30;
  if ((*(uint *)(unaff_EBP + -0x10) & 0x20000) != 0) {
    *(byte *)(unaff_EBP + -0xe) = *(byte *)(unaff_EBP + -0xe) & 0xfd;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0xe) & 1) != 0) {
    *(byte *)(unaff_EBP + -0xe) = *(byte *)(unaff_EBP + -0xe) & 0xfe;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0xb);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x32;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_SimsRaise_cur_006cab5c);
    *(byte *)(unaff_EBP + -0xe) = *(byte *)(unaff_EBP + -0xe) | 4;
    *(undefined1 *)(unaff_EBP + -4) = 0x33;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 0x80000;
    *(undefined4 *)(unaff_EBP + -4) = 0x34;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x35;
  if ((*(uint *)(unaff_EBP + -0x10) & 0x80000) != 0) {
    *(byte *)(unaff_EBP + -0xe) = *(byte *)(unaff_EBP + -0xe) & 0xf7;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0xe) & 4) != 0) {
    *(byte *)(unaff_EBP + -0xe) = *(byte *)(unaff_EBP + -0xe) & 0xfb;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,9);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x37;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_SimsRotate_cur_006cab4c);
    *(byte *)(unaff_EBP + -0xe) = *(byte *)(unaff_EBP + -0xe) | 0x10;
    *(undefined1 *)(unaff_EBP + -4) = 0x38;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 0x200000;
    *(undefined4 *)(unaff_EBP + -4) = 0x39;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x3a;
  if ((*(uint *)(unaff_EBP + -0x10) & 0x200000) != 0) {
    *(byte *)(unaff_EBP + -0xe) = *(byte *)(unaff_EBP + -0xe) & 0xdf;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0xe) & 0x10) != 0) {
    *(byte *)(unaff_EBP + -0xe) = *(byte *)(unaff_EBP + -0xe) & 0xef;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0xc);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x3c;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_SimsRotateNW_cur_006cab38);
    *(byte *)(unaff_EBP + -0xe) = *(byte *)(unaff_EBP + -0xe) | 0x40;
    *(undefined1 *)(unaff_EBP + -4) = 0x3d;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 0x800000;
    *(undefined4 *)(unaff_EBP + -4) = 0x3e;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x3f;
  if ((*(uint *)(unaff_EBP + -0x10) & 0x800000) != 0) {
    *(byte *)(unaff_EBP + -0xe) = *(byte *)(unaff_EBP + -0xe) & 0x7f;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0xe) & 0x40) != 0) {
    *(byte *)(unaff_EBP + -0xe) = *(byte *)(unaff_EBP + -0xe) & 0xbf;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0xd);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x41;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_SimsRotateNE_cur_006cab24);
    *(byte *)(unaff_EBP + -0xd) = *(byte *)(unaff_EBP + -0xd) | 1;
    *(undefined1 *)(unaff_EBP + -4) = 0x42;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 0x2000000;
    *(undefined4 *)(unaff_EBP + -4) = 0x43;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x44;
  if ((*(uint *)(unaff_EBP + -0x10) & 0x2000000) != 0) {
    *(byte *)(unaff_EBP + -0xd) = *(byte *)(unaff_EBP + -0xd) & 0xfd;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0xd) & 1) != 0) {
    *(byte *)(unaff_EBP + -0xd) = *(byte *)(unaff_EBP + -0xd) & 0xfe;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0xe);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x46;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_SimsRotateSW_cur_006cab10);
    *(byte *)(unaff_EBP + -0xd) = *(byte *)(unaff_EBP + -0xd) | 4;
    *(undefined1 *)(unaff_EBP + -4) = 0x47;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 0x8000000;
    *(undefined4 *)(unaff_EBP + -4) = 0x48;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x49;
  if ((*(uint *)(unaff_EBP + -0x10) & 0x8000000) != 0) {
    *(byte *)(unaff_EBP + -0xd) = *(byte *)(unaff_EBP + -0xd) & 0xf7;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0xd) & 4) != 0) {
    *(byte *)(unaff_EBP + -0xd) = *(byte *)(unaff_EBP + -0xd) & 0xfb;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0xf);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x4b;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_SimsRotateSE_cur_006caafc);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 0x10000000;
    *(undefined1 *)(unaff_EBP + -4) = 0x4c;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0xd) = *(byte *)(unaff_EBP + -0xd) | 0x20;
    *(undefined4 *)(unaff_EBP + -4) = 0x4d;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x4e;
  if ((*(byte *)(unaff_EBP + -0xd) & 0x20) != 0) {
    *(byte *)(unaff_EBP + -0xd) = *(byte *)(unaff_EBP + -0xd) & 0xdf;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(uint *)(unaff_EBP + -0x10) & 0x10000000) != 0) {
    *(byte *)(unaff_EBP + -0xd) = *(byte *)(unaff_EBP + -0xd) & 0xef;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x10);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x50;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_LEFT_cur_006caaf0);
    *(byte *)(unaff_EBP + -0xd) = *(byte *)(unaff_EBP + -0xd) | 0x40;
    *(undefined1 *)(unaff_EBP + -4) = 0x51;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0xd) = *(byte *)(unaff_EBP + -0xd) | 0x80;
    *(undefined4 *)(unaff_EBP + -4) = 0x52;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x53;
  if ((*(byte *)(unaff_EBP + -0xd) & 0x80) != 0) {
    *(byte *)(unaff_EBP + -0xd) = *(byte *)(unaff_EBP + -0xd) & 0x7f;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0xd) & 0x40) != 0) {
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x11);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x55;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_RIGHT_cur_006caae4);
    *(undefined4 *)(unaff_EBP + -0x14) = 1;
    *(undefined1 *)(unaff_EBP + -4) = 0x56;
    FUN_005b86bd(uVar6);
    *(undefined4 *)(unaff_EBP + -0x14) = 3;
    *(undefined4 *)(unaff_EBP + -4) = 0x57;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x58;
  if ((*(byte *)(unaff_EBP + -0x14) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffd;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x12);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x5a;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_UP_cur_006caadc);
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) | 4;
    *(undefined1 *)(unaff_EBP + -4) = 0x5b;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) | 8;
    *(undefined4 *)(unaff_EBP + -4) = 0x5c;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x5d;
  if ((*(byte *)(unaff_EBP + -0x14) & 8) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffff7;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x14) & 4) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffb;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x13);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x5f;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_DOWN_cur_006caad0);
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) | 0x10;
    *(undefined1 *)(unaff_EBP + -4) = 0x60;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) | 0x20;
    *(undefined4 *)(unaff_EBP + -4) = 0x61;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x62;
  if ((*(byte *)(unaff_EBP + -0x14) & 0x20) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xffffffdf;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x14) & 0x10) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xffffffef;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x14);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 100;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_UPRIGHT_cur_006caac4);
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) | 0x40;
    *(undefined1 *)(unaff_EBP + -4) = 0x65;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) | 0x80;
    *(undefined4 *)(unaff_EBP + -4) = 0x66;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x67;
  if ((*(byte *)(unaff_EBP + -0x14) & 0x80) != 0) {
    *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0x7f;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x14) & 0x40) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xffffffbf;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x15);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x69;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_UPLEFT_cur_006caab8);
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) | 1;
    *(undefined1 *)(unaff_EBP + -4) = 0x6a;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) | 2;
    *(undefined4 *)(unaff_EBP + -4) = 0x6b;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x6c;
  if ((*(byte *)(unaff_EBP + -0x13) & 2) != 0) {
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) & 0xfd;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x13) & 1) != 0) {
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) & 0xfe;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x16);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x6e;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_DOWNRIGHT_cur_006caaa8);
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) | 4;
    *(undefined1 *)(unaff_EBP + -4) = 0x6f;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) | 8;
    *(undefined4 *)(unaff_EBP + -4) = 0x70;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x71;
  if ((*(byte *)(unaff_EBP + -0x13) & 8) != 0) {
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) & 0xf7;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x13) & 4) != 0) {
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) & 0xfb;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x17);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x73;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_DOWNLEFT_cur_006caa98);
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) | 0x10;
    *(undefined1 *)(unaff_EBP + -4) = 0x74;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) | 0x20;
    *(undefined4 *)(unaff_EBP + -4) = 0x75;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x76;
  if ((*(byte *)(unaff_EBP + -0x13) & 0x20) != 0) {
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) & 0xdf;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x13) & 0x10) != 0) {
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) & 0xef;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x18);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x78;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_EXPLORE_cur_006caa8c);
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) | 0x40;
    *(undefined1 *)(unaff_EBP + -4) = 0x79;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) | 0x80;
    *(undefined4 *)(unaff_EBP + -4) = 0x7a;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x7b;
  if ((*(byte *)(unaff_EBP + -0x13) & 0x80) != 0) {
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) & 0x7f;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x13) & 0x40) != 0) {
    *(byte *)(unaff_EBP + -0x13) = *(byte *)(unaff_EBP + -0x13) & 0xbf;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x19);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x7d;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_DEADEXPL_cur_006caa7c);
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) | 1;
    *(undefined1 *)(unaff_EBP + -4) = 0x7e;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) | 2;
    *(undefined4 *)(unaff_EBP + -4) = 0x7f;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x80;
  if ((*(byte *)(unaff_EBP + -0x12) & 2) != 0) {
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) & 0xfd;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x12) & 1) != 0) {
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) & 0xfe;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x1a);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x82;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_pan_cur_006caa74);
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) | 4;
    *(undefined1 *)(unaff_EBP + -4) = 0x83;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) | 8;
    *(undefined4 *)(unaff_EBP + -4) = 0x84;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x85;
  if ((*(byte *)(unaff_EBP + -0x12) & 8) != 0) {
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) & 0xf7;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x12) & 4) != 0) {
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) & 0xfb;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x1b);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x87;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_LivePerson_cur_006caa64);
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) | 0x10;
    *(undefined1 *)(unaff_EBP + -4) = 0x88;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) | 0x20;
    *(undefined4 *)(unaff_EBP + -4) = 0x89;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x8a;
  if ((*(byte *)(unaff_EBP + -0x12) & 0x20) != 0) {
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) & 0xdf;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x12) & 0x10) != 0) {
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) & 0xef;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x1d);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x8c;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_LiveNothing_cur_006caa54);
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) | 0x40;
    *(undefined1 *)(unaff_EBP + -4) = 0x8d;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) | 0x80;
    *(undefined4 *)(unaff_EBP + -4) = 0x8e;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x8f;
  if ((*(byte *)(unaff_EBP + -0x12) & 0x80) != 0) {
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) & 0x7f;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x12) & 0x40) != 0) {
    *(byte *)(unaff_EBP + -0x12) = *(byte *)(unaff_EBP + -0x12) & 0xbf;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x1c);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x91;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_LivePet_cur_006caa48);
    *(byte *)(unaff_EBP + -0x11) = *(byte *)(unaff_EBP + -0x11) | 1;
    *(undefined1 *)(unaff_EBP + -4) = 0x92;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x11) = *(byte *)(unaff_EBP + -0x11) | 2;
    *(undefined4 *)(unaff_EBP + -4) = 0x93;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x94;
  if ((*(byte *)(unaff_EBP + -0x11) & 2) != 0) {
    *(byte *)(unaff_EBP + -0x11) = *(byte *)(unaff_EBP + -0x11) & 0xfd;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x11) & 1) != 0) {
    *(byte *)(unaff_EBP + -0x11) = *(byte *)(unaff_EBP + -0x11) & 0xfe;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x2a);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x96;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_LiveNothingPet_cur_006caa34);
    *(byte *)(unaff_EBP + -0x11) = *(byte *)(unaff_EBP + -0x11) | 4;
    *(undefined1 *)(unaff_EBP + -4) = 0x97;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x11) = *(byte *)(unaff_EBP + -0x11) | 8;
    *(undefined4 *)(unaff_EBP + -4) = 0x98;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x99;
  if ((*(byte *)(unaff_EBP + -0x11) & 8) != 0) {
    *(byte *)(unaff_EBP + -0x11) = *(byte *)(unaff_EBP + -0x11) & 0xf7;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x11) & 4) != 0) {
    *(byte *)(unaff_EBP + -0x11) = *(byte *)(unaff_EBP + -0x11) & 0xfb;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x2b);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x9b;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_LiveObjectAvail_cur_006caa20);
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) | 0x10000000;
    *(undefined1 *)(unaff_EBP + -4) = 0x9c;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x11) = *(byte *)(unaff_EBP + -0x11) | 0x20;
    *(undefined4 *)(unaff_EBP + -4) = 0x9d;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0x9e;
  if ((*(byte *)(unaff_EBP + -0x11) & 0x20) != 0) {
    *(byte *)(unaff_EBP + -0x11) = *(byte *)(unaff_EBP + -0x11) & 0xdf;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(uint *)(unaff_EBP + -0x14) & 0x10000000) != 0) {
    *(byte *)(unaff_EBP + -0x11) = *(byte *)(unaff_EBP + -0x11) & 0xef;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x1e);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0xa0;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_LiveObjectUnavail_cur_006caa08);
    *(byte *)(unaff_EBP + -0x11) = *(byte *)(unaff_EBP + -0x11) | 0x40;
    *(undefined1 *)(unaff_EBP + -4) = 0xa1;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x11) = *(byte *)(unaff_EBP + -0x11) | 0x80;
    *(undefined4 *)(unaff_EBP + -4) = 0xa2;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xa3;
  if ((*(byte *)(unaff_EBP + -0x11) & 0x80) != 0) {
    *(byte *)(unaff_EBP + -0x11) = *(byte *)(unaff_EBP + -0x11) & 0x7f;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x11) & 0x40) != 0) {
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x1f);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0xa5;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_AddPts_cur_006ca9fc);
    *(undefined4 *)(unaff_EBP + -0x18) = 1;
    *(undefined1 *)(unaff_EBP + -4) = 0xa6;
    FUN_005b86bd(uVar6);
    *(undefined4 *)(unaff_EBP + -0x18) = 3;
    *(undefined4 *)(unaff_EBP + -4) = 0xa7;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xa8;
  if ((*(byte *)(unaff_EBP + -0x18) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffd;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x20);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0xaa;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_MOVEIN_cur_006ca9f0);
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) | 4;
    *(undefined1 *)(unaff_EBP + -4) = 0xab;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) | 8;
    *(undefined4 *)(unaff_EBP + -4) = 0xac;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xad;
  if ((*(byte *)(unaff_EBP + -0x18) & 8) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffff7;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x18) & 4) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffb;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x21);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0xaf;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_bulldoze_cur_006ca9e0);
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) | 0x10;
    *(undefined1 *)(unaff_EBP + -4) = 0xb0;
    FUN_005b86bd(uVar6);
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) | 0x20;
    *(undefined4 *)(unaff_EBP + -4) = 0xb1;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xb2;
  if ((*(byte *)(unaff_EBP + -0x18) & 0x20) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xffffffdf;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x18) & 0x10) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xffffffef;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x22);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0xb4;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_SimsFlip_cur_006ca9d0);
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) | 0x40;
    *(undefined1 *)(unaff_EBP + -4) = 0xb5;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x18) = *(byte *)(unaff_EBP + -0x18) | 0x80;
    *(undefined4 *)(unaff_EBP + -4) = 0xb6;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xb7;
  if ((*(byte *)(unaff_EBP + -0x18) & 0x80) != 0) {
    *(byte *)(unaff_EBP + -0x18) = *(byte *)(unaff_EBP + -0x18) & 0x7f;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x18) & 0x40) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xffffffbf;
    FUN_00401729();
  }
  FUN_005e74f4(uVar6,0x23);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0xb9;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_RemovePts_cur_006ca9c0);
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) | 1;
    *(undefined1 *)(unaff_EBP + -4) = 0xba;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) | 2;
    *(undefined4 *)(unaff_EBP + -4) = 0xbb;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xbc;
  if ((*(byte *)(unaff_EBP + -0x17) & 2) != 0) {
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) & 0xfd;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x17) & 1) != 0) {
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) & 0xfe;
    FUN_00401a37();
  }
  FUN_005e74f4(uVar6,0x24);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0xbe;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_Taxi_cur_006ca9b4);
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) | 4;
    *(undefined1 *)(unaff_EBP + -4) = 0xbf;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) | 8;
    *(undefined4 *)(unaff_EBP + -4) = 0xc0;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xc1;
  if ((*(byte *)(unaff_EBP + -0x17) & 8) != 0) {
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) & 0xf7;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x17) & 4) != 0) {
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) & 0xfb;
    FUN_00401a37();
  }
  FUN_005e74f4(uVar6,0x25);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0xc3;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_Water_cur_006ca9a8);
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) | 0x10;
    *(undefined1 *)(unaff_EBP + -4) = 0xc4;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) | 0x20;
    *(undefined4 *)(unaff_EBP + -4) = 0xc5;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xc6;
  if ((*(byte *)(unaff_EBP + -0x17) & 0x20) != 0) {
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) & 0xdf;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x17) & 0x10) != 0) {
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) & 0xef;
    FUN_00401a37();
  }
  FUN_005e74f4(uVar6,0x26);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 200;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_Van_cur_006ca9a0);
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) | 0x40;
    *(undefined1 *)(unaff_EBP + -4) = 0xc9;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) | 0x80;
    *(undefined4 *)(unaff_EBP + -4) = 0xca;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xcb;
  if ((*(byte *)(unaff_EBP + -0x17) & 0x80) != 0) {
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) & 0x7f;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x17) & 0x40) != 0) {
    *(byte *)(unaff_EBP + -0x17) = *(byte *)(unaff_EBP + -0x17) & 0xbf;
    FUN_00401a37();
  }
  FUN_005e74f4(uVar6,0x27);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0xcd;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_Rezone2_cur_006ca994);
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) | 1;
    *(undefined1 *)(unaff_EBP + -4) = 0xce;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) | 2;
    *(undefined4 *)(unaff_EBP + -4) = 0xcf;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xd0;
  if ((*(byte *)(unaff_EBP + -0x16) & 2) != 0) {
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) & 0xfd;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x16) & 1) != 0) {
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) & 0xfe;
    FUN_00401a37();
  }
  FUN_005e74f4(uVar6,0x28);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0xd2;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_trolleybus_cur_006ca984);
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) | 4;
    *(undefined1 *)(unaff_EBP + -4) = 0xd3;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) | 8;
    *(undefined4 *)(unaff_EBP + -4) = 0xd4;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xd5;
  if ((*(byte *)(unaff_EBP + -0x16) & 8) != 0) {
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) & 0xf7;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x16) & 4) != 0) {
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) & 0xfb;
    FUN_00401a37();
  }
  FUN_005e74f4(uVar6,0x29);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0xd7;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_limo_cur_006ca978);
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) | 0x10;
    *(undefined1 *)(unaff_EBP + -4) = 0xd8;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) | 0x20;
    *(undefined4 *)(unaff_EBP + -4) = 0xd9;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xda;
  if ((*(byte *)(unaff_EBP + -0x16) & 0x20) != 0) {
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) & 0xdf;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x16) & 0x10) != 0) {
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) & 0xef;
    FUN_00401a37();
  }
  FUN_005e74f4(uVar6,0x2c);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0xdc;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_tram_cur_006ca96c);
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) | 0x40;
    *(undefined1 *)(unaff_EBP + -4) = 0xdd;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) | 0x80;
    *(undefined4 *)(unaff_EBP + -4) = 0xde;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xdf;
  if ((*(byte *)(unaff_EBP + -0x16) & 0x80) != 0) {
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) & 0x7f;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x16) & 0x40) != 0) {
    *(byte *)(unaff_EBP + -0x16) = *(byte *)(unaff_EBP + -0x16) & 0xbf;
    FUN_00401a37();
  }
  FUN_005e74f4(uVar6,0x2d);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0xe1;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_hole_cur_006ca960);
    *(byte *)(unaff_EBP + -0x15) = *(byte *)(unaff_EBP + -0x15) | 1;
    *(undefined1 *)(unaff_EBP + -4) = 0xe2;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x15) = *(byte *)(unaff_EBP + -0x15) | 2;
    *(undefined4 *)(unaff_EBP + -4) = 0xe3;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xe4;
  if ((*(byte *)(unaff_EBP + -0x15) & 2) != 0) {
    *(byte *)(unaff_EBP + -0x15) = *(byte *)(unaff_EBP + -0x15) & 0xfd;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x15) & 1) != 0) {
    *(byte *)(unaff_EBP + -0x15) = *(byte *)(unaff_EBP + -0x15) & 0xfe;
    FUN_00401a37();
  }
  FUN_005e74f4(uVar6,0x2e);
  pvVar8 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x24) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0xe6;
  if (pvVar8 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00412a04(unaff_EBP + -0x78,unaff_EBP + -0x30,s_balloon_cur_006ca954);
    *(byte *)(unaff_EBP + -0x15) = *(byte *)(unaff_EBP + -0x15) | 4;
    *(undefined1 *)(unaff_EBP + -4) = 0xe7;
    FUN_005b86bd(uVar6);
    *(byte *)(unaff_EBP + -0x15) = *(byte *)(unaff_EBP + -0x15) | 8;
    *(undefined4 *)(unaff_EBP + -4) = 0xe8;
    uVar6 = FUN_005e7372(unaff_EBP + -0x48);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xe9;
  if ((*(byte *)(unaff_EBP + -0x15) & 8) != 0) {
    *(byte *)(unaff_EBP + -0x15) = *(byte *)(unaff_EBP + -0x15) & 0xf7;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if ((*(byte *)(unaff_EBP + -0x15) & 4) != 0) {
    FUN_00401a37();
  }
  FUN_005e74f4(uVar6,0x2f);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

