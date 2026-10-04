
void __thiscall FUN_0041102a(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  bool bVar4;
  undefined *puVar5;
  undefined *puVar6;
  char *pcVar7;
  int local_c;
  int local_8;
  
  iVar1 = FUN_00635845(*(undefined4 *)(param_2 + 4),&DAT_006c0a78);
  if (iVar1 != 0) {
    iVar2 = *param_1;
    local_c = -1;
    if (-1 < (param_1[1] - iVar2) / 0x54) {
      local_8 = -0x54;
      do {
        bVar4 = local_c != -1;
        if (bVar4) {
          psVar3 = (short *)(local_8 + iVar2);
          puVar6 = (undefined *)(int)*psVar3;
          puVar5 = &DAT_006c12b0;
        }
        else {
          psVar3 = (short *)0x0;
          puVar6 = &DAT_006c12a8;
          puVar5 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar5,puVar6);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[1];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Members_006c129c;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[2];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Adult_Males_006c128c;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[3];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Adult_Females_006c127c;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[4];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Kid_Males_006c1270;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[5];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Kid_Females_006c1260;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[6];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Workers_006c1254;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[7];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Objects_006c1248;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = *(char **)(psVar3 + 8);
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s_Objects_Value_006c1238;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = *(char **)(psVar3 + 10);
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s_Architecture_Value_006c1224;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[0xc];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s_House_Square_Feet_006c1210;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[0xd];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s_House_Size_006c1204;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[0xe];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s_Furnishings_Rating_006c11f0;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[0xf];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s_Size_Rating_006c11e4;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[0x10];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s_Yard_Rating_006c11d8;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[0x11];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s_Upkeep_Rating_006c11c8;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[0x12];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s_Layout_Rating_006c11b8;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = *(char **)(psVar3 + 0x14);
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Income_006c11b0;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = *(char **)(psVar3 + 0x16);
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Bills_006c11a8;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = *(char **)(psVar3 + 0x18);
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Food_006c11a0;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = *(char **)(psVar3 + 0x1a);
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Maintenance_006c1190;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = *(char **)(psVar3 + 0x1c);
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Objects_006c1184;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = *(char **)(psVar3 + 0x1e);
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Misc_006c117c;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = *(char **)(psVar3 + 0x20);
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Arch_006c1174;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = *(char **)(psVar3 + 0x22);
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Funds_006c116c;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[0x24];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s_Romances_Out_006c115c;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[0x25];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s_Romances_In_006c1150;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[0x26];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s_Friends_Out_006c1144;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[0x27];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s_Friends_In_006c1138;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        if (bVar4) {
          pcVar7 = (char *)(int)psVar3[0x28];
          puVar6 = &DAT_006c12b0;
        }
        else {
          pcVar7 = s__Friends_006c112c;
          puVar6 = &DAT_006c12b4;
        }
        FUN_006357d8(iVar1,puVar6,pcVar7);
        FUN_006357d8(iVar1,&DAT_006c08dc);
        local_c = local_c + 1;
        iVar2 = *param_1;
        local_8 = local_8 + 0x54;
      } while (local_c < (param_1[1] - iVar2) / 0x54);
    }
    FUN_0063558d(iVar1);
  }
  return;
}

