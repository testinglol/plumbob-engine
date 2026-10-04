
undefined4 FUN_0055c263(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  iVar1 = _strcmp(&DAT_006c9c58,(char *)**(undefined4 **)(param_1 + 4));
  if (iVar1 == 0) {
    if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc == 2) {
      iVar1 = FUN_00635f62(*(undefined4 *)(*(int *)(param_1 + 4) + 0xc));
      if ((-1 < iVar1) && (iVar1 < 0x13)) {
        FUN_004f1b96(iVar1,0xffffffff);
        FUN_005dac30(0x10,param_2,iVar1);
        goto LAB_0055c4f9;
      }
      pcVar3 = s_house_num_must_be_between_0_and_1_006cdadc;
    }
    else {
      pcVar3 = s_Usage__load__house_num__006cdb00;
    }
LAB_0055c407:
    FUN_005d4bbf(pcVar3);
LAB_0055c511:
    uVar2 = 0;
  }
  else {
    iVar1 = _strcmp(s_stream_fps_006cd81c,(char *)**(undefined4 **)(param_1 + 4));
    if (iVar1 == 0) {
      if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 2) goto LAB_0055c511;
      FUN_00634d24(*(undefined4 *)(*(int *)(param_1 + 4) + 0xc),&DAT_006c5518,param_2 + 0x1f8);
    }
    else {
      iVar1 = _strcmp(s_reload_neighborhood_006cde24,(char *)**(undefined4 **)(param_1 + 4));
      if (iVar1 == 0) {
        FUN_004f5aa0(1);
      }
      else {
        iVar1 = _strcmp(s_move_lots_006cd7a4,(char *)**(undefined4 **)(param_1 + 4));
        if (iVar1 == 0) {
          if (*(char *)(param_2 + 0x120) == '\0') {
            FUN_0055b4e6(5);
          }
        }
        else {
          if (1 < (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc) {
            iVar1 = _strcmp(s_show_zones_006cdee4,(char *)**(undefined4 **)(param_1 + 4));
            if (iVar1 == 0) {
              iVar1 = _strcmp(&DAT_006c7110,*(char **)(*(int *)(param_1 + 4) + 0xc));
              if (iVar1 == 0) {
                *(undefined1 *)(param_2 + 0x118) = 1;
              }
              else {
                *(undefined1 *)(param_2 + 0x118) = 0;
              }
              FUN_0055d388();
              goto LAB_0055c4f9;
            }
          }
          iVar1 = _strcmp(s_nessie_006cd7f4,(char *)**(undefined4 **)(param_1 + 4));
          if (iVar1 != 0) {
            iVar1 = _strcmp(s_show_filter_006cde54,(char *)**(undefined4 **)(param_1 + 4));
            if (iVar1 == 0) {
              if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc < 2) {
                *(undefined4 *)(param_2 + 0x194) = 0;
              }
              else {
                uVar2 = FUN_00635f62(*(undefined4 *)(*(int *)(param_1 + 4) + 0xc));
                *(undefined4 *)(param_2 + 0x194) = uVar2;
              }
              iVar1 = *(int *)(param_2 + 0x194);
              if (-1 < iVar1) {
                if (2 < iVar1) {
                  if (iVar1 == 3) {
                    *(undefined4 *)(param_2 + 0x194) = 4;
                  }
                  else if (iVar1 == 4) {
                    *(undefined4 *)(param_2 + 0x194) = 8;
                  }
                  else if (iVar1 == 5) {
                    *(undefined4 *)(param_2 + 0x194) = 0x10;
                  }
                  else if (iVar1 == 6) {
                    *(undefined4 *)(param_2 + 0x194) = 0x20;
                  }
                  else {
                    if (iVar1 != 7) goto LAB_0055c4fd;
                    *(undefined4 *)(param_2 + 0x194) = 0x40;
                  }
                }
                FUN_0055d972(*(undefined4 *)(param_2 + 0x194));
                goto LAB_0055c4f9;
              }
LAB_0055c4fd:
              FUN_005d4bbf(s_Filter_number_must_be_between_0_a_006cdff4);
              *(undefined4 *)(param_2 + 0x194) = 0;
            }
            goto LAB_0055c511;
          }
          if (*(char *)(param_2 + 0x100) != '\0') {
            pcVar3 = s_Sorry_only_one_Nessie_at_a_time__006cdab8;
            goto LAB_0055c407;
          }
          *(undefined4 *)(param_2 + 0x10c) = 0xffffffff;
          *(undefined4 *)(param_2 + 0x114) = 0xffffffff;
          *(undefined1 *)(param_2 + 0x100) = 1;
          *(undefined4 *)(param_2 + 0x104) = 0x76;
          *(undefined4 *)(param_2 + 0x108) = 0x207;
        }
      }
    }
LAB_0055c4f9:
    uVar2 = 1;
  }
  return uVar2;
}

