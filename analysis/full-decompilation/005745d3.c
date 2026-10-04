
void FUN_005745d3(void)

{
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  FUN_00580a92(&local_c);
  if (local_c != 0) {
    local_10 = local_8;
    do {
      FUN_005763bc(&local_24,local_c + 4);
      FUN_0057482d(local_24,local_20,local_1c,local_18);
      local_10 = local_18;
      local_c = local_1c;
    } while (local_1c != 0);
  }
  return;
}

