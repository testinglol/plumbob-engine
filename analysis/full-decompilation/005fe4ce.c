
undefined4 __thiscall FUN_005fe4ce(int param_1,byte param_2)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  
  switch(*(undefined4 *)(param_1 + 8)) {
  case 1:
  case 2:
  case 0x12:
    if (param_2 == 1) {
      pcVar3 = s_Monday_006d84c8;
    }
    else if (param_2 == 2) {
      pcVar3 = s_Tuesday_006d84d0;
    }
    else if (param_2 == 3) {
      pcVar3 = s_Wednesday_006d84d8;
    }
    else if (param_2 == 4) {
      pcVar3 = s_Thursday_006d84e4;
    }
    else if (param_2 == 5) {
      pcVar3 = s_Friday_006d84f0;
    }
    else if (param_2 == 6) {
      pcVar3 = s_Saturday_006d84f8;
    }
    else {
      if (param_2 != 7) {
        return 1;
      }
      pcVar3 = s_Sunday_006d8504;
    }
    break;
  case 3:
    if (param_2 == 1) {
      pcVar3 = s_Lundi_006d8848;
    }
    else if (param_2 == 2) {
      pcVar3 = s_Mardi_006d8850;
    }
    else if (param_2 == 3) {
      pcVar3 = s_Mercredi_006d8858;
    }
    else if (param_2 == 4) {
      pcVar3 = (char *)0x6d8864;
    }
    else if (param_2 == 5) {
      pcVar3 = s_Vendredi_006d886c;
    }
    else if (param_2 == 6) {
      pcVar3 = s_Samedi_006d8878;
    }
    else {
      if (param_2 != 7) {
        return 1;
      }
      pcVar3 = s_Dimanche_006d8880;
    }
    break;
  case 4:
    if (param_2 == 1) {
      pcVar3 = s_Montag_006d8804;
    }
    else if (param_2 == 2) {
      pcVar3 = s_Dienstag_006d880c;
    }
    else if (param_2 == 3) {
      pcVar3 = s_Mittwoch_006d8818;
    }
    else if (param_2 == 4) {
      pcVar3 = s_Donnerstag_006d8824;
    }
    else if (param_2 == 5) {
      pcVar3 = s_Freitag_006d8830;
    }
    else if (param_2 == 6) {
      pcVar3 = s_Samstag_006d8838;
    }
    else {
      if (param_2 != 7) {
        return 1;
      }
      pcVar3 = s_Sonntag_006d8840;
    }
    break;
  case 5:
    if (param_2 == 1) {
      pcVar3 = (char *)0x6d86c4;
    }
    else if (param_2 == 2) {
      pcVar3 = (char *)0x6d86cc;
    }
    else if (param_2 == 3) {
      pcVar3 = (char *)0x6d86d4;
    }
    else if (param_2 == 4) {
      pcVar3 = (char *)0x6d86e0;
    }
    else if (param_2 == 5) {
      pcVar3 = (char *)0x6d86e8;
    }
    else if (param_2 == 6) {
      pcVar3 = s_Sabato_006d86f0;
    }
    else {
      if (param_2 != 7) {
        return 1;
      }
      pcVar3 = s_Domenica_006d86f8;
    }
    break;
  case 6:
    uVar1 = (uint)param_2;
    if (uVar1 == 1) {
      pcVar3 = s_Lunes_006d87d8;
      break;
    }
    if (uVar1 == 2) {
      pcVar3 = s_Martes_006d87e0;
      break;
    }
    if (uVar1 == 3) {
      pcVar3 = (char *)0x6d87e8;
      break;
    }
    if (uVar1 == 4) {
      pcVar3 = s_Jueves_006d87f4;
      break;
    }
    iVar2 = uVar1 - 5;
    if (iVar2 == 0) {
      pcVar3 = s_Viernes_006d87fc;
      break;
    }
    goto code_r0x005fe603;
  case 7:
    if (param_2 == 1) {
      pcVar3 = s_Maandag_006d8704;
    }
    else if (param_2 == 2) {
      pcVar3 = s_Dinsdag_006d870c;
    }
    else if (param_2 == 3) {
      pcVar3 = s_Woensdag_006d8714;
    }
    else if (param_2 == 4) {
      pcVar3 = s_Donderdag_006d8720;
    }
    else if (param_2 == 5) {
      pcVar3 = (char *)0x6d872c;
    }
    else if (param_2 == 6) {
      pcVar3 = s_Zaterdag_006d8734;
    }
    else {
      if (param_2 != 7) {
        return 1;
      }
      pcVar3 = s_Zondag_006d8740;
    }
    break;
  case 8:
    if (param_2 == 1) {
code_r0x005fe85f:
      pcVar3 = s_mandag_006d8638;
      break;
    }
    if (param_2 == 2) {
code_r0x005fe855:
      pcVar3 = (char *)0x6d8640;
      break;
    }
    if (param_2 == 3) {
code_r0x005fe84b:
      pcVar3 = (char *)0x6d8648;
      break;
    }
    if (param_2 == 4) {
code_r0x005fe841:
      pcVar3 = (char *)0x6d8650;
      break;
    }
    if (param_2 == 5) {
code_r0x005fe837:
      pcVar3 = s_fredag_006d8658;
      break;
    }
    if (param_2 != 6) {
      if (param_2 != 7) {
        return 1;
      }
      pcVar3 = (char *)0x6d8668;
      break;
    }
    goto code_r0x005fe82d;
  case 9:
    if (param_2 == 1) {
      pcVar3 = (char *)0x6d8748;
    }
    else if (param_2 == 2) {
      pcVar3 = (char *)0x6d8750;
    }
    else if (param_2 == 3) {
      pcVar3 = (char *)0x6d8758;
    }
    else if (param_2 == 4) {
      pcVar3 = (char *)0x6d8760;
    }
    else if (param_2 == 5) {
      pcVar3 = s_Fredag_006d8768;
    }
    else if (param_2 == 6) {
      pcVar3 = (char *)0x6d8770;
    }
    else {
      if (param_2 != 7) {
        return 1;
      }
      pcVar3 = (char *)0x6d8778;
    }
    break;
  case 10:
    if (param_2 == 1) goto code_r0x005fe85f;
    if (param_2 == 2) goto code_r0x005fe855;
    if (param_2 == 3) goto code_r0x005fe84b;
    if (param_2 == 4) goto code_r0x005fe841;
    if (param_2 == 5) goto code_r0x005fe837;
    if (param_2 != 6) {
      if (param_2 != 7) {
        return 1;
      }
      pcVar3 = (char *)0x6d8670;
      break;
    }
code_r0x005fe82d:
    pcVar3 = (char *)0x6d8660;
    break;
  case 0xb:
    if (param_2 == 1) {
      pcVar3 = s_Maanantai_006d8678;
    }
    else if (param_2 == 2) {
      pcVar3 = s_Tiistai_006d8684;
    }
    else if (param_2 == 3) {
      pcVar3 = (char *)0x6d868c;
    }
    else if (param_2 == 4) {
      pcVar3 = s_Torstai_006d8698;
    }
    else if (param_2 == 5) {
      pcVar3 = s_Perjantai_006d86a0;
    }
    else if (param_2 == 6) {
      pcVar3 = s_Lauantai_006d86ac;
    }
    else {
      if (param_2 != 7) {
        return 1;
      }
      pcVar3 = s_Sunnuntai_006d86b8;
    }
    break;
  case 0xc:
    if (param_2 == 1) {
      pcVar3 = (char *)0x6d8604;
    }
    else if (param_2 == 2) {
      pcVar3 = (char *)0x6d860c;
    }
    else if (param_2 == 3) {
      pcVar3 = (char *)0x6d8614;
    }
    else if (param_2 == 4) {
      pcVar3 = (char *)0x6d861c;
    }
    else if (param_2 == 5) {
      pcVar3 = (char *)0x6d8624;
    }
    else if (param_2 == 6) {
      pcVar3 = (char *)0x6d862c;
    }
    else {
      if (param_2 != 7) {
        return 1;
      }
      pcVar3 = (char *)0x6d8630;
    }
    break;
  case 0xd:
    if (param_2 == 1) {
      pcVar3 = (char *)0x6d85c4;
    }
    else if (param_2 == 2) {
      pcVar3 = (char *)0x6d85d0;
    }
    else if (param_2 == 3) {
      pcVar3 = (char *)0x6d85d8;
    }
    else if (param_2 == 4) {
      pcVar3 = (char *)0x6d85e0;
    }
    else if (param_2 == 5) {
      pcVar3 = (char *)0x6d85e8;
    }
    else if (param_2 == 6) {
      pcVar3 = (char *)0x6d85f0;
    }
    else {
      if (param_2 != 7) {
        return 1;
      }
      pcVar3 = (char *)0x6d85f8;
    }
    break;
  case 0xe:
    uVar1 = (uint)param_2;
    if (uVar1 == 1) {
      pcVar3 = s_Segunda_feira_006d8780;
      break;
    }
    if (uVar1 == 2) {
      pcVar3 = (char *)0x6d8790;
      break;
    }
    if (uVar1 == 3) {
      pcVar3 = s_Quarta_feira_006d879c;
      break;
    }
    if (uVar1 == 4) {
      pcVar3 = s_Quinta_feira_006d87ac;
      break;
    }
    iVar2 = uVar1 - 5;
    if (iVar2 == 0) {
      pcVar3 = s_Sexta_feira_006d87bc;
      break;
    }
code_r0x005fe603:
    if (iVar2 == 1) {
      pcVar3 = (char *)0x6d87c8;
    }
    else {
      if (iVar2 != 2) {
        return 1;
      }
      pcVar3 = s_Domingo_006d87d0;
    }
    break;
  case 0xf:
    if (param_2 == 1) {
      pcVar3 = (char *)0x6d8544;
    }
    else if (param_2 == 2) {
      pcVar3 = (char *)0x6d854c;
    }
    else if (param_2 == 3) {
      pcVar3 = (char *)0x6d8554;
    }
    else if (param_2 == 4) {
      pcVar3 = (char *)0x6d855c;
    }
    else if (param_2 == 5) {
      pcVar3 = (char *)0x6d8564;
    }
    else if (param_2 == 6) {
      pcVar3 = (char *)0x6d856c;
    }
    else {
      if (param_2 != 7) {
        return 1;
      }
      pcVar3 = (char *)0x6d8574;
    }
    break;
  case 0x10:
    if (param_2 == 1) {
      pcVar3 = (char *)0x6d857c;
    }
    else if (param_2 == 2) {
      pcVar3 = (char *)0x6d858c;
    }
    else if (param_2 == 3) {
      pcVar3 = (char *)0x6d8594;
    }
    else if (param_2 == 4) {
      pcVar3 = s_Czwartek_006d859c;
    }
    else if (param_2 == 5) {
      pcVar3 = (char *)0x6d85a8;
    }
    else if (param_2 == 6) {
      pcVar3 = s_Sobota_006d85b0;
    }
    else {
      if (param_2 != 7) {
        return 1;
      }
      pcVar3 = s_Niedziela_006d85b8;
    }
    break;
  case 0x11:
    if (param_2 == 1) {
      pcVar3 = (char *)0x6d850c;
    }
    else if (param_2 == 2) {
      pcVar3 = (char *)0x6d8514;
    }
    else if (param_2 == 3) {
      pcVar3 = (char *)0x6d851c;
    }
    else if (param_2 == 4) {
      pcVar3 = (char *)0x6d8524;
    }
    else if (param_2 == 5) {
      pcVar3 = (char *)0x6d852c;
    }
    else if (param_2 == 6) {
      pcVar3 = (char *)0x6d8534;
    }
    else {
      if (param_2 != 7) {
        return 1;
      }
      pcVar3 = (char *)0x6d853c;
    }
    break;
  case 0x13:
    if (param_2 == 1) {
      pcVar3 = &DAT_006d84ac;
    }
    else if (param_2 == 2) {
      pcVar3 = &DAT_006d84b0;
    }
    else if (param_2 == 3) {
      pcVar3 = &DAT_006d84b4;
    }
    else if (param_2 == 4) {
      pcVar3 = &DAT_006d84b8;
    }
    else if (param_2 == 5) {
      pcVar3 = &DAT_006d84bc;
    }
    else if (param_2 == 6) {
      pcVar3 = &DAT_006d84c0;
    }
    else {
      if (param_2 != 7) {
        return 1;
      }
      pcVar3 = &DAT_006d84c4;
    }
    break;
  default:
    FUN_005d49b7(s_untranslated_006d849c);
    return 0;
  }
  FUN_005d49b7(pcVar3);
  return 1;
}

