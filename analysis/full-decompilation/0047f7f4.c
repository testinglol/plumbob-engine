
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047f7f4(short *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  float10 fVar4;
  int iVar5;
  undefined1 local_220 [272];
  undefined **local_110;
  undefined4 local_10c;
  undefined1 local_104 [256];
  
  FUN_0046fb9b(local_104,0x100);
  local_110 = &PTR_LAB_0066655c;
  FUN_0046fa24();
  iVar3 = (int)*param_1;
  FUN_00452bb4();
  iVar5 = iVar3;
  uVar2 = FUN_00401f6f();
  cVar1 = FUN_00582e2a(uVar2,iVar5);
  if (cVar1 == '\0') {
    uVar2 = FUN_00401f73();
    cVar1 = FUN_00582e2a(uVar2,iVar3);
    if (cVar1 == '\0') {
      FUN_0046fa40();
      goto LAB_0047f890;
    }
  }
  FUN_0046f917(local_220,0xffffffff);
LAB_0047f890:
  if ((*(byte *)(param_1 + 2) & 0x10) != 0) {
    FUN_0046f847(s___auto_vary_006c555c,0xffffffff);
  }
  if ((*(byte *)(param_1 + 2) & 1) != 0) {
    FUN_0046f847(s___looped_006c5550,0xffffffff);
  }
  if ((*(byte *)(param_1 + 2) & 2) != 0) {
    FUN_0046f847(s___with_stack_obj_as_source_006c5534,0xffffffff);
  }
  if ((~*(byte *)(param_1 + 2) & 4) == 0) {
    FUN_0046f847(s___no_zoom_006c5528,0xffffffff);
  }
  if ((~*(byte *)(param_1 + 2) & 8) == 0) {
    FUN_0046f847(s___no_pan_006c551c,0xffffffff);
  }
  fVar4 = (float10)FUN_0047f978();
  if (fVar4 != (float10)_DAT_00667280) {
    fVar4 = (float10)FUN_0047f978();
    FUN_00635858(local_10c,&DAT_006c5518,(double)fVar4);
    FUN_0046f847(s___sampled_at_006c5508,0xffffffff);
    FUN_0046f917(&local_110,0xffffffff);
  }
  if (*(char *)((int)param_1 + 5) != '\0') {
    FUN_0046f847(s___volume_006c54fc,0xffffffff);
    FUN_0046fa40();
  }
  FUN_0046fa24();
  return;
}

